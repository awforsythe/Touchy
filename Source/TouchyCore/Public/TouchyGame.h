#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "TouchyGame.generated.h"

UCLASS()
class ATouchyGame : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATouchyGame(const FObjectInitializer& ObjectInitializer);
};
