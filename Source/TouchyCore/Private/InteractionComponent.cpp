#include "InteractionComponent.h"

void UInteractionComponent::Used(class APawn* Pawn)
{
	NativeOnUsed.ExecuteIfBound(Pawn);
	OnUsed.Broadcast(Pawn);
}
