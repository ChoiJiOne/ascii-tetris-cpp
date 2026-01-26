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

void Tetromino::Reset()
{
	// TODO: 수정 예정 (임시 코드)
	const Position& startPosition = _ctx->GetStartPosition();
	_ctx->SetTile(startPosition.x, startPosition.y, ETile::WALL);
	_ctx->SetTile(startPosition.x + 1, startPosition.y, ETile::WALL);
	_ctx->SetTile(startPosition.x + 2, startPosition.y, ETile::WALL);
	_ctx->SetTile(startPosition.x + 3, startPosition.y, ETile::WALL);
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
