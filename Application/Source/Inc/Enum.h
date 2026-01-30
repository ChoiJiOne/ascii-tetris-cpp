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