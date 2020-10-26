#include "TouchyPawn.h"

#include "Log.h"
#include "TouchyTypes.h"
#include "InteractionTrace.h"
#include "InteractibleActor.h"
#include "Interactible.h"

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

void ATouchyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("Use"), IE_Pressed, this, &ATouchyPawn::OnUsePressed);
}

void ATouchyPawn::OnUsePressed()
{
	// Check the InteractionTrace to find the actor in the center of our view (if any)
	AActor* Actor = (InteractionTrace && InteractionTrace->Hit.bBlockingHit) ? InteractionTrace->Hit.Actor.Get() : nullptr;

	// Here we demonstrate multiple ways of implementing a simple interaction system;
	// in an actual game project you'd usually just want to pick one.

	// 1. Inheritance via base class (AInteractibleActor)
	AInteractibleActor* InteractibleActor = Cast<AInteractibleActor>(Actor);
	if (InteractibleActor)
	{
		InteractibleActor->Used(this);
	}

	// 2. Inheritance via interface (IInteractible)
	if (Actor && Actor->Implements<UInteractible>())
	{
		IInteractible::Execute_Used(Actor, this);
	}
}
