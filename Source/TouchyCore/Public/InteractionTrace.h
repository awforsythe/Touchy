#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"

#include "InteractionTrace.generated.h"

/** Helper object used to run a per-frame line trace in order to find the
	closest actor that blocks a particular trace channel. Call Update each frame
	and pass in a locally-controlled pawn; check Hit.bBlockingHit to determine
	if the most recent trace has a valid hit result.
*/
UCLASS(Config=Game)
class UInteractionTrace : public UObject
{
	GENERATED_BODY()

public:
	/** How far into the scene (from the player's POV) we should trace to find interactible objects. */
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category="Interaction")
	float TraceDistance;

	/** If enabled, we'll render debug lines to visualize the results of the trace. */
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category="Interaction")
	bool bDebugDraw;

public:
	/** Cached hit result from the last line trace we ran; bBlockingHit indicates whether we hit anything. */
	UPROPERTY(Transient, VisibleAnywhere, BlueprintReadOnly, Category="Interaction|State")
	FHitResult Hit;

public:
	UInteractionTrace(const FObjectInitializer& ObjectInitializer);
	void Update(class UWorld* World, class APawn* OwningPawn, ECollisionChannel TraceChannel);
};
