#pragma once

enum class ETileState
{
	EMPTY  = 0x00,
	WALL   = 0x01,
	ACTIVE = 0x02,
	FIXED  = 0x03,
};

enum class EMoveDirection
{
	NONE  = 0x00,
	LEFT  = 0x01,
	RIGHT = 0x02,
	UP    = 0x03,
	DOWN  = 0x04,
};

enum class EMoveResult
{
	BLOCKED = 0x00,
	MOVED   = 0x01,
};

// NOTE: https://ko.wikipedia.org/wiki/%ED%85%8C%ED%8A%B8%EB%A1%9C%EB%AF%B8%EB%85%B8
enum class ETetrominoType
{
	I,
	O,
	T,
	J,
	L,
	S,
	Z,
};