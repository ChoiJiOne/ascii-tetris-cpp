#pragma once

#include <cstdint>
#include <vector>

#include "Macro.h"
#include "Result.h"

#include "Enum.h"
#include "Tile.h"

class GameContext
{
public:
	GameContext();
	virtual ~GameContext();

	DISALLOW_COPY_AND_ASSIGN(GameContext);

	void Reset();

private:
	bool _isDirtyTile = false;

	int32_t _rowSize = 20; // 세로 크기
	int32_t _colSize = 18; // 가로 크기

	std::vector<Tile> _tiles;

	Position _minPosition = { 0, 0 };
	Position _maxPosition = { 0, 0 };
	Position _startPosition = { 0, 0 };
};