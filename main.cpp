#include <iostream>
#include <cassert>
#include <array>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

const int Width = 800;
const int Height = 600;

extern "C"
{
	__declspec(dllexport) unsigned long NvOptimusEnablement = 0x00000001;
}

int main() {
	assert(glfwInit() == GLFW_TRUE);

	GLFWwindow* Window = glfwCreateWindow(Width, Height, "Blue Marble", nullptr, nullptr);
	assert(Window);

	glfwMakeContextCurrent(Window);

	assert(glewInit() == GLEW_OK);

	GLint GLMajorVersion = 0;
	GLint GLMinorVersion = 0;

	glGetIntegerv(GL_MAJOR_VERSION, &GLMajorVersion);
	glGetIntegerv(GL_MINOR_VERSION, &GLMinorVersion);

	std::cout << "OpenGL Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "OpenGL Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "GLSL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

	std::array<glm::vec3, 3> triangle = {
		glm::vec3{-1.0f, -1.0f, 0.0f},
		glm::vec3{1.0f, -1.0f, 0.0f},
		glm::vec3{0.0f, 1.0f, 0.0f}
	};

	GLuint vertexBuffer;

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle.data(), GL_STATIC_DRAW);

	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);

	while (!glfwWindowShouldClose(Window)) {
		glClear(GL_COLOR_BUFFER_BIT);

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwPollEvents();

		glfwSwapBuffers(Window);
	}

	glfwTerminate();
	return 0;
}