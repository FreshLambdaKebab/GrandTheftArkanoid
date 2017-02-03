#ifndef _GAME_SCENE_H
#define _GAME_SCENE_H

#include "SystemDefs.h"
#include <GLFW\glfw3.h>

enum class GameState
{
	GAME_PLAY,
	GAME_MENU,
	GAME_WON
};

class GameScene
{
public:
	GameScene(GLuint width,GLuint height);
	~GameScene();

	void Init();
	void Draw();
	void Update(GLfloat dt);
	void ProcessInput(GLfloat dt);
	void HandleCollision();

	void InitShaders();
	void LoadTextures();

	//getters
	GameState GetState() { return m_state; }

	//setters
	 void SetState(GameState state) { m_state = state; }

	 //key stuff
	 GLboolean keys[1024];
	 GLboolean keysProcessed[1024];
private:
	GameState m_state;
	GLuint m_width, m_height;

	//level & life shit
	GLint m_level;
	GLuint m_lives;
};

#endif