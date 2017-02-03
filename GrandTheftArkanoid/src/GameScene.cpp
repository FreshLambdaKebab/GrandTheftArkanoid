#include "GameScene.h"
#include <sstream>

GameScene::GameScene(GLuint width, GLuint height):
	m_state(GameState::GAME_PLAY),
	m_width(width),
	m_height(height),
	keys(),
	m_level(0)
{
}

GameScene::~GameScene()
{
}

void GameScene::Init()
{
	InitShaders();
	LoadTextures();

	//initialize all game objects etc.

}

void GameScene::Draw()
{
	//if on any state, render the main graphics
	if (m_state == GameState::GAME_PLAY || m_state == GameState::GAME_MENU || m_state == GameState::GAME_WON)
	{
		
	}

	//specific menu rendering
	if (m_state == GameState::GAME_MENU)
	{
		//display text bs
	}

	//specific game winning state rendering
	if (m_state == GameState::GAME_WON)
	{
		//display text bs
	}
}

void GameScene::Update(GLfloat dt)
{
	HandleCollision();
}

void GameScene::ProcessInput(GLfloat dt)
{
	if (m_state == GameState::GAME_MENU)
	{
		//do menu input here
	}

	if (m_state == GameState::GAME_PLAY)
	{
		//do gameplay input here
	}

	if (m_state == GameState::GAME_WON)
	{
		//do game won input here
	}
}

void GameScene::HandleCollision()
{
}

void GameScene::InitShaders()
{
}

void GameScene::LoadTextures()
{
}
