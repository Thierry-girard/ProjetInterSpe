// Using SDL, SDL OpenGL and standard IO
#include <iostream>
#include <cmath>

// Charge les paramètres de base
#include "settings.h"

// Module for space geometry
#include "geometry.h"
// Module for generating and rendering forms
#include "forms.h"
// Module for objects
#include "master.h"
// Module for textures
#include <SDL_image.h>


// How many frames time values to keep
// The higher the value the smoother the result is...
// Don't make it 0 or less :)
#define FRAME_VALUES 10




using namespace std;

int rotate_x = 15;
int rotate_y = 0;

const double WIDTH_TABLE = 100;
const double LENGTH_TABLE = 190;

/***************************************************************************/
/* Constants and functions declarations                                    */
/***************************************************************************/
// Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 800;

// Max number of forms : static allocation
const int MAX_FORMS_NUMBER = 10;

// Animation actualization delay (in ms) => 100 updates per second
const Uint32 ANIM_DELAY = 10;

// An array to store frame times:
Uint32 frametimes[FRAME_VALUES];

// Last calculated SDL_GetTicks
Uint32 frametimelast;

// total frames rendered
Uint32 framecount;

// the value you want
float framespersecond;


// Starts up SDL, creates window, and initializes OpenGL
bool init(SDL_Window** window, SDL_GLContext* context);

// Initializes matrices and clear color
bool initGL();

// Updating forms for animation
void update(Table *);

// Renders scene to the screen
const void render(Table *, const Point &cam_pos);

// Frees media and shuts down SDL
void close(SDL_Window** window);

// This function gets called once on startup.
void fpsinit();
void fpsthink();


/***************************************************************************/
/* Functions implementations                                               */
/***************************************************************************/
bool init(SDL_Window** window, SDL_GLContext* context)
{
    // Initialization flag
    bool success = true;

    // Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << endl;
        success = false;
    }
    else
    {
        // Use OpenGL 2.1
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

        // Create window
        *window = SDL_CreateWindow( "Projet Billard", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );
        if( *window == NULL )
        {
            cout << "Window could not be created! SDL Error: " << SDL_GetError() << endl;
            success = false;
        }
        else
        {
            // Create context
            *context = SDL_GL_CreateContext(*window);
            if( *context == NULL )
            {
                cout << "OpenGL context could not be created! SDL Error: " << SDL_GetError() << endl;
                success = false;
            }
            else
            {
                // Use Vsync
                if(SDL_GL_SetSwapInterval(1) < 0)
                {
                    cout << "Warning: Unable to set VSync! SDL Error: " << SDL_GetError() << endl;
                }

                // Initialize OpenGL
                if( !initGL() )
                {
                    cout << "Unable to initialize OpenGL!"  << endl;
                    success = false;
                }
            }
        }
    }

    return success;
}


bool initGL()
{
    bool success = true;
    GLenum error = GL_NO_ERROR;

    // Initialize Projection Matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Set the viewport : use all the window to display the rendered scene
    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    // Fix aspect ratio and depth clipping planes
    gluPerspective(40.0, (GLdouble)SCREEN_WIDTH/SCREEN_HEIGHT, 1.0, 5000.0);


    // Initialize Modelview Matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Initialize clear color : black with no transparency
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f );

    // Activate Z-Buffer


    // Check for error
    error = glGetError();
    if( error != GL_NO_ERROR )
    {
        cout << "Error initializing OpenGL!  " << gluErrorString( error ) << endl;
        success = false;
    }

	fpsinit();

    return success;
}

void update(Table * Table_Element)
{
    // Update the table
    if (Table_Element != NULL) {
        Table_Element->update(NULL);
    }
}

const void render(Table * Table_Element, const Point &cam_pos)
{
    // Clear color buffer and Z-Buffer
    glClear(GL_COLOR_BUFFER_BIT);

    // Initialize Modelview Matrix
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    // Set the camera position and parameters
	gluLookAt(cam_pos.x, cam_pos.y, cam_pos.z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // X, Y and Z axis
    glPushMatrix(); // Preserve the camera viewing point for further forms

    // Render the coordinates system
    glBegin(GL_LINES);
    {
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3i(0, 0, 0);
        glVertex3i(50, 0, 0);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3i(0, 0, 0);
        glVertex3i(0, 50, 0);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3i(0, 0, 0);
        glVertex3i(0, 0, 50);
    }
    glEnd();
    glPopMatrix();

	// ********************************************
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glScaled(1, 1, 1);

	glRotated(rotate_x, 1, 0, 0);
	glRotated(rotate_y, 0, 1, 0);
	glTranslated(- WIDTH_TABLE / 2, 0, - LENGTH_TABLE / 2);

    // Render the table

    if (Table_Element != NULL) {
        glPushMatrix(); // Preserve the camera viewing point for further forms
        Table_Element->render();
        glPopMatrix(); // Restore the camera viewing point for next object
    }
}

void close(SDL_Window** window)
{
    //Destroy window
    SDL_DestroyWindow(*window);
    *window = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}


// This function gets called once on startup.
void fpsinit() {

	// Set all frame times to 0ms.
	memset(frametimes, 0, sizeof(frametimes));
	framecount = 0;
	framespersecond = 0;
	frametimelast = SDL_GetTicks();

}

void fpsthink() {
	Uint32 frametimesindex;
	Uint32 getticks;
	Uint32 count;
	Uint32 i;
	// frametimesindex is the position in the array. It ranges from 0 to FRAME_VALUES.
	// This value rotates back to 0 after it hits FRAME_VALUES.
	frametimesindex = framecount % FRAME_VALUES;

	// store the current time
	getticks = SDL_GetTicks();

	// save the frame time value
	frametimes[frametimesindex] = getticks - frametimelast;

	// save the last frame time for the next fpsthink
	frametimelast = getticks;

	// increment the frame count
	framecount++;

	// Work out the current framerate

	// The code below could be moved into another function if you don't need the value every frame.

	// I've included a test to see if the whole array has been written to or not. This will stop
	// strange values on the first few (FRAME_VALUES) frames.
	if (framecount < FRAME_VALUES) {
		count = framecount;
	}
	else {
		count = FRAME_VALUES;
	}

	// add up all the values and divide to get the average frame time.
	framespersecond = 0;
	for (i = 0; i < count; i++) {
		framespersecond += frametimes[i];
	}
	framespersecond /= count;
	// now to make it an actual frames per second value...
	framespersecond = 1000.f / framespersecond;
	cout << "FPS : " << framespersecond << endl;

}


/***************************************************************************/
/* MAIN Function                                                           */
/***************************************************************************/
int main(int argc, char* args[])
{
    // The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    // OpenGL context
    SDL_GLContext gContext;


    // Start up SDL and create window
    if( !init(&gWindow, &gContext))
    {
        cout << "Failed to initialize!" << endl;
    }
    else
    {
        // Main loop flag
        bool quit = false;
        Uint32 current_time, previous_time;

        // Event handler
        SDL_Event event;

        // Camera position
        Point camera_position(0, 0, 2 * LENGTH_TABLE);

        // Create the Table
		Table * Table_Element = new Table(Point(0, -1, 0), Size(WIDTH_TABLE, 1, LENGTH_TABLE));

        // Get first "current time"
        previous_time = SDL_GetTicks();
        // While application is running
        while(!quit)
        {
			fpsthink();
            // Handle events on queue
            while(SDL_PollEvent(&event) != 0)
            {
                int x = 0, y = 0;
                SDL_Keycode key_pressed = event.key.keysym.sym;

                switch(event.type)
                {
                // User requests quit
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                    // Handle key pressed with current mouse position
                    SDL_GetMouseState( &x, &y );

                    switch(key_pressed)
                    {
                    // Quit the program when 'q' or Escape keys are pressed
                    case SDLK_q:
                    case SDLK_ESCAPE:
                        quit = true;
                        break;
					case SDLK_UP:
						rotate_x += 5;
						break;
					case SDLK_DOWN:
						rotate_x -= 5;
						break;
					case SDLK_LEFT:
						rotate_y += 5;
						break;
					case SDLK_RIGHT:
						rotate_y -= 5;
						break;
                    default:
                        break;
                    }
                    break;
                default:
                    break;
                }
            }

            // Update the scene
            current_time = SDL_GetTicks(); // get the elapsed time from SDL initialization (ms)
            if ((current_time - previous_time) > ANIM_DELAY)
            {
                previous_time = current_time;
                update(Table_Element);
            }

            // Render the scene
            render(Table_Element, camera_position);

            // Update window screen
            SDL_GL_SwapWindow(gWindow);
        }
    }

    // Free resources and close SDL
    close(&gWindow);

    return 0;
}
