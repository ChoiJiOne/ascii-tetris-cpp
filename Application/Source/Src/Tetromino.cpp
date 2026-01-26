#include "GenericAssert.h"
#include "InputManager.h"

#include "Tetromino.h"

Tetromino::Tetromino(GameContext* ctx)
{
	CHECK(ctx != nullptr);
	_ctx = ctx;

	_inputMgr = InputManager::GetPtr();
	CHECK(_inputMgr != nullptr);

	_isInitialized = true;
}

Tetromino::~Tetromino() {}

void Tetromino::Tick(float deltaSeconds)
{

}

void Tetromino::Release()
{
	if (!_isInitialized)
	{
		return;
	}

	_ctx = nullptr;
	_isInitialized = false;
}
