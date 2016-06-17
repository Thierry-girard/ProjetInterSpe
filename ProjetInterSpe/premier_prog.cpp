// Using SDL, SDL OpenGL and standard IO
#include <iostream>
#include <cmath>

// Charge les paramètres
#include "settings.h"

// Module for space geometry
#include "geometry.h"
// Module for generating and rendering forms
#include "forms.h"


using namespace std;

int rotate_x = 30;
int rotate_y = 315;
float rotate_0 = 0;
float rotate_1 = 0;

float scale = 500.0f;

/***************************************************************************/
/* Constants and functions declarations                                    */
/***************************************************************************/
// Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Max number of forms : static allocation
const int MAX_FORMS_NUMBER = 10;

// Animation actualization delay (in ms) => 100 updates per second
const Uint32 ANIM_DELAY = 10;


// Starts up SDL, creates window, and initializes OpenGL
bool init(SDL_Window** window, SDL_GLContext* context);

// Initializes matrices and clear color
bool initGL();

// Updating forms for animation
void update(Form* formlist[MAX_FORMS_NUMBER]);

// Renders scene to the screen
const void render(Form* formlist[MAX_FORMS_NUMBER], const Point &cam_pos);

// Frees media and shuts down SDL
void close(SDL_Window** window);


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
        *window = SDL_CreateWindow( "TP intro OpenGL / SDL 2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );
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

    return success;
}

void update(Form* formlist[MAX_FORMS_NUMBER])
{
    // Update the list of forms
    unsigned short i = 0;
    while(formlist[i] != NULL)
    {
        formlist[i]->getAnim().update();
        i++;
    }
}

const void render(Form* formlist[MAX_FORMS_NUMBER], const Point &cam_pos)
{
    // Clear color buffer and Z-Buffer
    glClear(GL_COLOR_BUFFER_BIT);

    // Initialize Modelview Matrix
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    // Set the camera position and parameters
    gluLookAt(cam_pos.x,cam_pos.y,cam_pos.z, 0.0,0.0,0.0, 0.0,1.0,0.0);

    // X, Y and Z axis
    glPushMatrix(); // Preserve the camera viewing point for further forms

    // Render the coordinates system
    glBegin(GL_LINES);
    {
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3i(0, 0, 0);
        glVertex3i(1, 0, 0);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3i(0, 0, 0);
        glVertex3i(0, 1, 0);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3i(0, 0, 0);
        glVertex3i(0, 0, 1);
    }
    glEnd();
    glPopMatrix();

	// ********************************************
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glScaled(0.5, 0.5, 0.5);

	glRotated(rotate_x, 1, 0, 0);
	glRotated(rotate_y, 0, 1, 0);

    // Render a simple object
    glPushMatrix(); // Preserve the camera viewing point for further forms
    /*glBegin(GL_QUADS);
    {
		// Front
		glColor3f(1, 1, 1);
		glVertex3i(1, 1, 1);
		glColor3f(1, 1, 0);
		glVertex3i(-1, 1, 1);
		glColor3f(1, 0, 0);
		glVertex3i(-1, -1, 1);
		glColor3f(1, 0, 1);
		glVertex3i(1, -1, 1);
		
		// Back
		glColor3f(0, 1, 1);
		glVertex3i(1, 1, -1);
		glColor3f(0, 1, 0);
		glVertex3i(-1, 1, -1);
		glColor3f(1, 1, 1);
		glVertex3i(-1, -1, -1);
		glColor3f(0, 0, 1);
		glVertex3i(1, -1, -1);

		// Top
		glColor3f(1, 1, 1);
		glVertex3i(1, 1, 1);
		glColor3f(1, 1, 0);
		glVertex3i(-1, 1, 1);
		glColor3f(0, 1, 0);
		glVertex3i(-1, 1, -1);
		glColor3f(0, 1, 1);
		glVertex3i(1, 1, -1);

		// Bot
		glColor3f(1, 0, 1);
		glVertex3i(1, -1, 1);
		glColor3f(1, 0, 0);
		glVertex3i(-1, -1, 1);
		glColor3f(1, 1, 1);
		glVertex3i(-1, -1, -1);
		glColor3f(0, 0, 1);
		glVertex3i(1, -1, -1);

		// Left
		glColor3f(1, 1, 0);
		glVertex3i(-1, 1, 1);
		glColor3f(1, 0, 0);
		glVertex3i(-1, -1, 1);
		glColor3f(1, 1, 1);
		glVertex3i(-1, -1, -1);
		glColor3f(0, 1, 0);
		glVertex3i(-1, 1, -1);

		// Right
		glColor3f(1, 1, 1);
		glVertex3i(1, 1, 1);
		glColor3f(1, 0, 1);
		glVertex3i(1, -1, 1);
		glColor3f(0, 0, 1);
		glVertex3i(1, -1, -1);
		glColor3f(0, 1, 1);
		glVertex3i(1, 1, -1);
    }
    glEnd();*/
    glPopMatrix(); // Restore the camera viewing point for next object

    // Render the list of forms
    unsigned short i = 0;
    while(formlist[i] != NULL)
    {
        glPushMatrix(); // Preserve the camera viewing point for further forms
        formlist[i]->render();
        glPopMatrix(); // Restore the camera viewing point for next object
        i++;
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
        Point camera_position(0, 0.0, 1000.0);

        // The forms to render
        Form* forms_list[MAX_FORMS_NUMBER];
        unsigned short number_of_forms = 0, i;
        forms_list[number_of_forms] = NULL; // Do nothing but remove a warning
        for (i=0; i<MAX_FORMS_NUMBER; i++)
        {
            forms_list[i] = NULL;
        }
        // Create here specific forms and add them to the list...
        // Don't forget to update the actual number_of_forms !
		forms_list[0] = new Sphere(Point(0, 0, 0), 21, Color(1, 0.5, 0));
		forms_list[0]->setAnim(Animation(0, 0.5, Vector(1, 0, 0)));
		forms_list[1] = new Sphere(Point(57, 0, 0), 0.002 * scale, Color(1, 0, 0));
		forms_list[1]->setAnim(Animation(0, 0.5, Vector(0, 1, 0)));
		forms_list[2] = new Sphere(Point(108, 0, 0), 0.006 * scale, Color(1, 0.5, 0));
		forms_list[2]->setAnim(Animation(0, 0.5, Vector(0, 1, 0)));
		forms_list[3] = new Sphere(Point(150, 0, 0), 0.006 * scale, Color(0, 0.25, 1));
		forms_list[3]->setAnim(Animation(0, 0.5, Vector(0, 1, 0)));
		forms_list[4] = new Sphere(Point(227, 0, 0), 0.003 * scale, Color(1, 0.5, 0.25));
		forms_list[4]->setAnim(Animation(0, 0.5, Vector(0, 1, 0)));
		forms_list[5] = new Sphere(Point(778, 0, 0), 0.07 * scale, Color(1, 1, 0.5));
		forms_list[5]->setAnim(Animation(0, 0.5, Vector(0, 1, 0)));
		forms_list[6] = new Sphere(Point(1429, 0, 0), 0.06 * scale, Color(1, 1, 0.25));
		forms_list[6]->setAnim(Animation(0, 0.5, Vector(0, 1, 0)));
		forms_list[7] = new Sphere(Point(2877, 0, 0), 0.025 * scale, Color(0.75, 0.75, 1));
		forms_list[7]->setAnim(Animation(0, 0.5, Vector(0, 1, 0)));
		forms_list[8] = new Sphere(Point(4498, 0, 0), 0.024 * scale, Color(0, 0, 1));
		forms_list[8]->setAnim(Animation(0, 0.5, Vector(0, 1, 0)));

        // Get first "current time"
        previous_time = SDL_GetTicks();
        // While application is running
        while(!quit)
        {
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
                update(forms_list);
            }

            // Render the scene
            render(forms_list, camera_position);

            // Update window screen
            SDL_GL_SwapWindow(gWindow);
        }
    }

    // Free resources and close SDL
    close(&gWindow);

    return 0;
}
