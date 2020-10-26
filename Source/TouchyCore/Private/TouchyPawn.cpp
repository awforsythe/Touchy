#include "TouchyPawn.h"

#include "TouchyTypes.h"
#include "InteractionTrace.h"

ATouchyPawn::ATouchyPawn(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.DoNotCreateDefaultSubobject(ADefaultPawn::MeshComponentName))
{
}

void ATouchyPawn::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (IsLocallyControlled())
	{
		if (!InteractionTrace)
		{
			InteractionTrace = NewObject<UInteractionTrace>(this);
			ensureMsgf(InteractionTrace, TEXT("Failed to create InteractionTrace object for locally-controlled pawn!"));
		}

		InteractionTrace->Update(GetWorld(), this, ECC_Interaction);
	}
}
