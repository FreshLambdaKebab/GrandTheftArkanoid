#pragma once

#include "SystemDefs.h"
#include <GLFW\glfw3.h>

class Framework
{
public:
	Framework();
	~Framework();

	void Initialize();
	void Run();

private:
	GLFWwindow* m_window;

	GLfloat m_deltaTime;
	GLfloat m_lastFrame;

};

