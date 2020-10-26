#include "TouchyPawn.h"

#include "Log.h"
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

void ATouchyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("Use"), IE_Pressed, this, &ATouchyPawn::OnUsePressed);
}

void ATouchyPawn::OnUsePressed()
{
	// Check the InteractionTrace to find the actor in the center of our view (if any)
	AActor* Actor = (InteractionTrace && InteractionTrace->Hit.bBlockingHit) ? InteractionTrace->Hit.Actor.Get() : nullptr;
	if (Actor)
	{
		UE_LOG(LogTouchyCore, Log, TEXT("Use: '%s'"), *Actor->GetName());
	}
	else
	{
		UE_LOG(LogTouchyCore, Log, TEXT("Use: <no actor>"));
	}
}
