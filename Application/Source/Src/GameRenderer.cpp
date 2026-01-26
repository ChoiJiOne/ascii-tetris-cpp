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
	};
}

GameRenderer::~GameRenderer() {}

void GameRenderer::Render()
{
	RenderTile();
}

void GameRenderer::RenderTile()
{
	if (!_gameCtx->IsDirtyTile())
	{
		return;
	}

	_consoleMgr->MoveCursor(0, 0);
	int32_t rowSize = _gameCtx->GetRowSize();
	int32_t colSize = _gameCtx->GetColSize();

	for (int32_t y = 0; y < rowSize; ++y)
	{
		for (int32_t x = 0; x < colSize; ++x)
		{
			const Tile& tile = _gameCtx->GetTile(x, y);
			auto it = _tileCharMap.find(tile.GetState());
			if (it != _tileCharMap.end())
			{
				_consoleMgr->Print(x, y, it->second, tile.GetColor());
			}
		}
	}

	_gameCtx->SetDirtyTile(false);
}