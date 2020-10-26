#include "InteractibleActor.h"

void AInteractibleActor::Used(APawn* Pawn)
{
	// Do nothing by default; just forward to our Blueprint implementation
	ReceiveUsed(Pawn);
}
