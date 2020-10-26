#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "InteractionComponent.generated.h"

/** Can be added to an actor in order to expose an event that fired when the
	player looks at the actor and presses the 'Use' button. The actor should
	also block the 'Interactible' collision trace channel.
*/
UCLASS(meta=(BlueprintSpawnableComponent))
class TOUCHYCORE_API UInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	DECLARE_DELEGATE_OneParam(FNativeOnUsedSignature, class APawn*);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUsedSignature, class APawn*, Pawn);

	FNativeOnUsedSignature NativeOnUsed; //!< Allows actors defined in C++ to bind to interaction events

	/** Fired when the player interacts with the owning actor. */
	UPROPERTY(BlueprintAssignable, Category="Interaction")
	FOnUsedSignature OnUsed;

public:
	/** Called when the player interacts with the owning actor; by default, just fires the OnUsed delegate. */
	virtual void Used(class APawn* Pawn);
};
