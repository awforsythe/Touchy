#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DefaultPawn.h"

#include "TouchyPawn.generated.h"

UCLASS()
class ATouchyPawn : public ADefaultPawn
{
	GENERATED_BODY()

public:
	ATouchyPawn(const FObjectInitializer& ObjectInitializer);
};
