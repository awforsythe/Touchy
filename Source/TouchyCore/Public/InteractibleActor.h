#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "InteractibleActor.generated.h"

/** Base class for actors that the player can interact with by pressing the
	"use" button while looking at them. The actor should have one or more
	collision primitives that block the 'Interaction' trace channel.
*/
UCLASS()
class AInteractibleActor : public AActor
{
	GENERATED_BODY()

public:
	/** Can be overridden by subclasses to respond to interaction in C++. */
	virtual void Used(class APawn* Pawn);

public:
	/** Allows Blueprint subclasses to respond to interactions. */
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Used"))
	void ReceiveUsed(class APawn* Pawn);
};
