#include "StringUtils.h"

#include "GameRenderer.h"

GameRenderer::GameRenderer(ConsoleManager* consoleMgr, GameContext* gameCtx)
	: _consoleMgr(consoleMgr)
	, _gameCtx(gameCtx)
{
	_tileCharMap =
	{
		{ ETileState::EMPTY, ' ' },
		{ ETileState::WALL, '#' },
		{ ETileState::ACTIVE, 'O' },
		{ ETileState::FIXED, 'X' },
	};
}

GameRenderer::~GameRenderer() {}

void GameRenderer::Render()
{
	RenderTile();
}

void GameRenderer::RenderTile()
{
}