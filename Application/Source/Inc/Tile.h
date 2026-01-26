#pragma once

#include "ConsoleManager.h"

#include "Enum.h"
#include "Position.h"

class Tile
{
public:
	Tile(const Position& position)
		: _position(position) {}

	Tile(const Position& position, const ETileState& state, const EConsoleColor& color)
		: _position(position)
		, _state(state)
		, _color(color) {}

	Tile(Tile&& instance) noexcept
		: _position(instance._position)
		, _state(instance._state)
		, _color(instance._color) {}

	Tile(const Tile& instance) noexcept 
		: _position(instance._position)
		, _state(instance._state)
		, _color(instance._color) {}

	virtual ~Tile() {}

	Tile& operator=(Tile&& instance) noexcept
	{
		if (this == &instance) return *this;

		_position = instance._position;
		_state = instance._state;
		_color = instance._color;

		return *this;
	}

	Tile& operator=(const Tile& instance) noexcept
	{
		if (this == &instance) return *this;

		_position = instance._position;
		_state = instance._state;
		_color = instance._color;

		return *this;
	}

	const Position& GetPosition() const { return _position; }
	ETileState GetState() const { return _state; }
	EConsoleColor GetColor() const { return _color; }

	void SetState(ETileState state) { _state = state; }
	void SetColor(EConsoleColor color) { _color = color; }

private:
	Position _position = { 0, 0 };
	ETileState _state = ETileState::EMPTY;
	EConsoleColor _color = EConsoleColor::WHITE;
};