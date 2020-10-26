#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "Interactible.generated.h"

/** Interface used by objects that can respond when the player looks at them
	and presses the 'Use' button. Objects that implement the Interactible
	interface should also block the 'Interactible' trace channel.
*/
UINTERFACE()
class TOUCHYCORE_API UInteractible : public UInterface
{
	GENERATED_BODY()
};

/** Native interface: C++ classes can extend IInteractible and override the
	virtual Used_Implementation function; Blueprint classes will receive a Used
	Blueprint event.
*/
class TOUCHYCORE_API IInteractible
{
	GENERATED_BODY()

public:
	/** Called when a locally-controlled pawn looks at this object and presses the Use button. */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Interaction")
	void Used(class APawn* Pawn);

	virtual void Used_Implementation(class APawn* Pawn) {};
};
