#include "Framework.h"

GameScene Arkanoid(SCREEN_WIDTH, SCREEN_HEIGHT);

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

Framework::Framework():
	m_deltaTime(0.0f),
	m_lastFrame(0.0f),
	m_window(nullptr)
{
}

Framework::~Framework()
{
	// terminate glfw resources
	glfwTerminate();
}

void Framework::Initialize()
{
	// initialize GLFW
	glfwInit();
	//set options for glfw
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
	glfwWindowHint(GLFW_SAMPLES, 4);

	// create glfw window
	m_window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "GrandTheftArkanoid ~ version 0.1", nullptr, nullptr);
	glfwMakeContextCurrent(m_window);

	// Set the required callback functions
	glfwSetKeyCallback(m_window, key_callback);

	// set to true for modern opengl calls
	glewExperimental = GL_TRUE;
	glewInit();
	glGetError();

	//define viewport dimensions
	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//initialize the game scene object
	Arkanoid.Init();
}

void Framework::Run()
{
	//set the state to the playing state
	Arkanoid.SetState(GameState::GAME_PLAY);

	// Game loop
	while (!glfwWindowShouldClose(m_window))
	{
		//calcualte delta time of current frame
		GLfloat currentFrame = glfwGetTime();
		m_deltaTime = currentFrame - m_lastFrame;
		m_lastFrame = currentFrame;
		glfwPollEvents();

		//handle user input
		Arkanoid.ProcessInput(m_deltaTime);

		//update game state
		Arkanoid.Update(m_deltaTime);

		// Render
		glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
  
		//render game
		Arkanoid.Draw();

		// Swap the screen buffers
		glfwSwapBuffers(m_window);
	}
}

void key_callback(GLFWwindow * window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	//game key callback
	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
			Arkanoid.keys[key] = true;
		else if (action == GLFW_RELEASE)
			Arkanoid.keys[key] = false;
		Arkanoid.keysProcessed[key] = false;
	}
}
