#pragma once

#include "GameScene.h"

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

