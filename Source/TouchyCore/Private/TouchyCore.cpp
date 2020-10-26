#include "TouchyCore.h"
#include "Modules/ModuleManager.h"

#include "Log.h"

void FTouchyCore::StartupModule()
{
	UE_LOG(LogTouchyCore, Log, TEXT("TouchyCore module starting up"));
}

void FTouchyCore::ShutdownModule()
{
	UE_LOG(LogTouchyCore, Log, TEXT("TouchyCore module shutting down"));
}

IMPLEMENT_PRIMARY_GAME_MODULE(FTouchyCore, TouchyCore, "TouchyCore");
