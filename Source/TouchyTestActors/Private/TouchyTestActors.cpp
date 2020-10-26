#include "TouchyTestActors.h"
#include "Modules/ModuleManager.h"

#include "Log.h"

void FTouchyTestActors::StartupModule()
{
	UE_LOG(LogTouchyTestActors, Log, TEXT("TouchyTestActors module starting up"));
}

void FTouchyTestActors::ShutdownModule()
{
	UE_LOG(LogTouchyTestActors, Log, TEXT("TouchyTestActors module shutting down"));
}

IMPLEMENT_GAME_MODULE(FTouchyTestActors, TouchyTestActors);
