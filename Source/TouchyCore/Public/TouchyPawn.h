#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DefaultPawn.h"

#include "TouchyPawn.generated.h"

UCLASS()
class ATouchyPawn : public ADefaultPawn
{
	GENERATED_BODY()

public:
	/** Helper object that runs a per-frame line trace for interactible objects and caches the hit result. Only exists for locally-controlled pawns. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Interaction")
	class UInteractionTrace* InteractionTrace;

public:
	ATouchyPawn(const FObjectInitializer& ObjectInitializer);
	virtual void Tick(float DeltaSeconds) override;
};
