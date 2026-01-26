#pragma once

#include <cstdint>
#include <vector>

#include "Macro.h"

#include "Enum.h"
#include "Tile.h"

class GameContext
{
public:
	GameContext();
	virtual ~GameContext();

	DISALLOW_COPY_AND_ASSIGN(GameContext);

	void Reset();

	void SetDirtyTile(bool isDirty) { _isDirtyTile = isDirty; }
	void SetTile(int32_t x, int32_t y, const ETileState& state, const EConsoleColor& color, bool bForceSet = false);
	void SetTile(const Position& position, const ETileState& state, const EConsoleColor& color);

	const Tile& GetTile(int32_t x, int32_t y) const;
	const Tile& GetTile(const Position& position) const;
	const int32_t& GetRowSize() const { return _rowSize; }
	const int32_t& GetColSize() const { return _colSize; }
	const Position& GetStartPosition() const { return _startPosition; }

	bool IsDirtyTile() const { return _isDirtyTile; }
	bool IsValidTile(int32_t x, int32_t y) const;
	bool IsValidTile(const Position& position) const;
	bool IsOutline(int32_t x, int32_t y) const;
	bool IsOutline(const Position& position) const;
	bool HasEmptyTile() const;

	bool CanMoveTo(int32_t srcX, int32_t srcY, int32_t dstX, int32_t dstY);
	bool CanMoveTo(const Position& srcPosition, const Position& dstPosition);
	void MoveTo(int32_t srcX, int32_t srcY, int32_t dstX, int32_t dstY, bool bKeepSrc = false);
	void MoveTo(const Position& srcPosition, const Position& dstPosition, bool bKeepSrc = false);

	bool CanSwap(int32_t srcX, int32_t srcY, int32_t dstX, int32_t dstY);
	bool CanSwap(const Position& srcPosition, const Position& dstPosition);
	void Swap(int32_t srcX, int32_t srcY, int32_t dstX, int32_t dstY);
	void Swap(const Position& srcPosition, const Position& dstPosition);

	bool CanMove(int32_t x, int32_t y, const EMoveDirection& moveDirection);
	bool CanMove(const Position& position, const EMoveDirection& moveDirection);
	EMoveResult Move(int32_t& x, int32_t& y, const EMoveDirection& moveDirection, bool bKeepSrc = false);
	EMoveResult Move(Position& position, const EMoveDirection& moveDirection, bool bKeepSrc = false);

private:
	bool _isDirtyTile = false;

	int32_t _rowSize = 20; // 세로 크기
	int32_t _colSize = 18; // 가로 크기

	std::vector<Tile> _tiles;

	Position _minPosition = { 0, 0 };
	Position _maxPosition = { 0, 0 };
	Position _startPosition = { 0, 0 };
};