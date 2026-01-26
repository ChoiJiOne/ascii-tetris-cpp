#include "App.h"
#include "Tetromino.h"

App::App() 
	: _renderer(ConsoleManager::GetPtr(), &_ctx)
{
}

Result<void> App::OnStartup(const AppContext& appCtx)
{
	ConsoleManager* consoleMgr = appCtx.GetConsoleManager();
	if (consoleMgr == nullptr)
	{
		return Result<void>::Fail(MAKE_ERROR(EErrorCode::INVALID_ARGUMENT, "INVALID_CONSOLE_MANAGER_FROM_APP_CONTEXT"));
	}

	consoleMgr->SetVisibleCursor(false);
	consoleMgr->SetTitle("Tetris"); // TODO: 하드 코딩 제거 필요.
	consoleMgr->Clear();

	Tetromino* tetromino = appCtx.GetActorManager()->Create<Tetromino>(&_ctx);
	_actors =
	{
		tetromino,
	};

	_ctx.Reset();

	return Result<void>::Success();
}

void App::OnPreTick(const AppContext& appCtx, float deltaSeconds)
{
	InputManager* inputMgr = appCtx.GetInputManager();
	if (inputMgr->GetKeyPress(EKey::ESCAPE) == EPress::PRESSED)
	{
		appCtx.RequestQuit();
	}
}

void App::OnTick(const AppContext& appCtx, float deltaSeconds)
{
	for (auto& actor : _actors)
	{
		actor->Tick(deltaSeconds);
	}
}

void App::OnPostTick(const AppContext& appCtx, float deltaSeconds)
{
}

void App::OnRender(const AppContext& appCtx)
{
	_renderer.Render();
}

Result<void> App::OnShutdown(const AppContext& appCtx)
{
	ConsoleManager* consoleMgr = appCtx.GetConsoleManager();
	if (consoleMgr == nullptr)
	{
		return Result<void>::Fail(MAKE_ERROR(EErrorCode::INVALID_ARGUMENT, "INVALID_CONSOLE_MANAGER_FROM_APP_CONTEXT"));
	}

	consoleMgr->SetVisibleCursor(true);

	return Result<void>::Success();
}