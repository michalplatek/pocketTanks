#ifndef _TEXT_H_
#define _TEXT_H_


// GLM
#include <glm.hpp>
#include <matrix_transform.hpp>
#include <type_ptr.hpp>
// FreeType
#include <ft2build.h>
#include FT_FREETYPE_H

#include "Config.h"
#include <map>
#include "Renderable.h"
#include "FreeGlutHelper.h"
#include "Shader.h"


class Text : public Renderable {
public:
	Text(Config *config);
	~Text();
	void render();
	void renderText(Shader &shader, std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color);
	void configureText(Config *config);
};

#endif