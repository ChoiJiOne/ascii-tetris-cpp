#pragma once

#include <functional>
#include <map>

#include "IActor.h"
#include "GameContext.h"

class InputManager;

class Tetromino : public IActor
{
public:
	Tetromino(GameContext* ctx);
	virtual ~Tetromino();

	DISALLOW_COPY_AND_ASSIGN(Tetromino);

	virtual void Tick(float deltaSeconds) override;
	virtual void Release() override;

	void Reset();

private:
	GameContext* _ctx = nullptr;
	InputManager* _inputMgr = nullptr;

	std::map<EKey, std::function<void()>> _keyActionMap;
};