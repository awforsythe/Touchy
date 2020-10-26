#include "TouchyGame.h"

#include "TouchyPlayerController.h"
#include "TouchyPawn.h"

ATouchyGame::ATouchyGame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PlayerControllerClass = ATouchyPlayerController::StaticClass();
	DefaultPawnClass = ATouchyPawn::StaticClass();
}
