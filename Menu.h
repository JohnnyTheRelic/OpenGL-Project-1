#pragma once

#include "Mesh.h"
#include "Model.h"
#include <vector>

class Menu {

public:
	Menu(GLFWwindow* window, Camera camera, Shader shaderProgram, std::vector<Model> models);
	void Run();
private:
	GLFWwindow* window;
	Camera camera;
	std::vector<Model> models;
	Shader shaderProgram;
	bool paused = false;
	bool enterPressed = false;
	
};