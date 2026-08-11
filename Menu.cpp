#include "Menu.h";

Menu::Menu(GLFWwindow* window, Camera camera, Shader shaderProgram,std::vector<Model> models) : window(window), camera(camera), shaderProgram(shaderProgram),
 models(models) {
	
}

void Menu::Run() {
	while (!glfwWindowShouldClose(window))
	{
		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// Tell OpenGL which Shader Program we want to use
		bool enterPressing = glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS;
		if (!enterPressing && enterPressed) {
			paused = !paused;
			
		}
		enterPressed = enterPressing;
		if (!paused) {
			camera.Inputs(window);
			camera.updateMatrix(45.0f, 0.1f, 100.0f);
		}

		for (Model model : models) {
			model.Draw(shaderProgram, camera);
		}
		/*model2.Draw(shaderProgram, camera);*/

		/*GLenum err = glGetError();
		if (err != GL_NO_ERROR)
			std::cout << "GL Error: " << err << '\n';*/




			// Bind the VAO so OpenGL knows to use it
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}
}