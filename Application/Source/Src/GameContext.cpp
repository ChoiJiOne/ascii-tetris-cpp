#include "GenericAssert.h"

#include "GameContext.h"

GameContext::GameContext()
{
	_minPosition = { 1, 1 };
	_maxPosition = { _colSize - 2, _rowSize - 2 };
	_startPosition = { _colSize / 3, 1 };

	for (int32_t y = 0; y < _rowSize; ++y)
	{
		for (int32_t x = 0; x < _colSize; ++x)
		{
			_tiles.push_back(Tile(Position{ x, y }));
		}
	}
}

GameContext::~GameContext() {}

void GameContext::Reset()
{
	for (int32_t y = 0; y < _rowSize; ++y)
	{
		for (int32_t x = 0; x < _colSize; ++x)
		{
			ETileState tileState = ETileState::EMPTY;
			if ((x <= 0 || x >= _colSize - 1) || (y <= 0 || y >= _rowSize - 1))
			{
				tileState = ETileState::WALL;
			}

			int32_t offset = y * _colSize + x;
			_tiles[offset].SetState(tileState);
		}
	}
}