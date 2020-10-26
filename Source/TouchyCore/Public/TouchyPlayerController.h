#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "TouchyPlayerController.generated.h"

UCLASS()
class ATouchyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATouchyPlayerController(const FObjectInitializer& ObjectInitializer);
};
