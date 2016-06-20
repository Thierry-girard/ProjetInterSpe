#include <cmath>
#include <SDL_opengl.h>
#include <GL/GLU.h>
#include "forms.h"
#include <SDL_image.h>
#include <iostream>

using namespace std;


Form::Form(GLchar* path) {
	if (path != NULL)
		texture = LoadTexture(path);
	else
		texture = NULL;
}


GLuint Form::LoadTexture(GLchar* path)
{
	SDL_Surface *tex_surf = IMG_Load(path);
	if (!tex_surf) {
		cout << "Failed to load texture " << IMG_GetError() << endl;
		return 0;
	}
	// work out what format to tell glTexImage2D to use...
	int mode;
	if (tex_surf->format->BytesPerPixel == 3) { // RGB 24bit
		mode = GL_RGB;
	}
	else if (tex_surf->format->BytesPerPixel == 4) { // RGBA 32bit
		mode = GL_RGBA;
	}
	else {
		SDL_FreeSurface(tex_surf);
		return 0;
	}
	GLuint texture_id;
	glGenTextures(1, &texture_id);
	// tell opengl to use the generated texture name
	glBindTexture(GL_TEXTURE_2D, texture_id);
	// this reads from the sdl imgsurf and puts it into an opengl texture
	glTexImage2D(GL_TEXTURE_2D, 0, mode, tex_surf->w, tex_surf->h, 0, mode, GL_UNSIGNED_BYTE, tex_surf->pixels);
	// these affect how this texture is drawn later on...
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// clean up
	SDL_FreeSurface(tex_surf);
	return texture_id;
}
