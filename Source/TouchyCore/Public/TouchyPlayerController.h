#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "TouchyPlayerController.generated.h"

UCLASS()
class ATouchyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Interaction")
	float InteractionTraceDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Interaction")
	bool bInteractionDebugDraw;

public:
	ATouchyPlayerController(const FObjectInitializer& ObjectInitializer);
	virtual void PlayerTick(float DeltaTime);
};
