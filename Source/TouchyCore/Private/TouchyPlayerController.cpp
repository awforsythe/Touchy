#include "TouchyPlayerController.h"

#include "Engine/World.h"
#include "DrawDebugHelpers.h"

#include "TouchyTypes.h"

ATouchyPlayerController::ATouchyPlayerController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	InteractionTraceDistance = 100.0f;
	bInteractionDebugDraw = true;
}

void ATouchyPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	// Only run interaction traces if we're currently controlling a pawn
	UWorld* World = GetWorld();
	APawn* ControlledPawn = GetPawn();
	if (World && ControlledPawn)
	{
		// Get the player POV: this gives us a world-space ray pointing into the center of the screen
		FVector ViewLocation;
		FRotator ViewRotation;
		GetPlayerViewPoint(ViewLocation, ViewRotation);

		// Prepare the input parameters for the line trace
		const FVector& TraceStart = ViewLocation;
		const FVector TraceEnd = TraceStart + (ViewRotation.Vector() * InteractionTraceDistance);
		const ECollisionChannel TraceChannel = ECC_Interaction;
		const FCollisionQueryParams QueryParams(TEXT("PlayerInteraction"), false, ControlledPawn);
		const FCollisionResponseParams ResponseParams(ECR_Block);

		// Run the line trace, seeing if we hit anything that blocks the interaction channel
		FHitResult Hit;
		if (World->LineTraceSingleByChannel(Hit, TraceStart, TraceEnd, TraceChannel, QueryParams, ResponseParams))
		{
			// If debug drawing is enabled, visualize the hit location and normal
			if (bInteractionDebugDraw)
			{
				DrawDebugLine(World, TraceStart, Hit.ImpactPoint, FColor::Green, false, -1.0f, SDPG_World, 3.0f);
				DrawDebugDirectionalArrow(World, Hit.ImpactPoint, Hit.ImpactPoint + Hit.ImpactNormal * 50.0f, 10.0f, FColor::Yellow, false, -1.0f, SDPG_World, 3.0f);
			}
		}
		else
		{
			// If debug drawing is enabled, visualize the extent of the trace
			if (bInteractionDebugDraw)
			{
				DrawDebugLine(World, TraceStart, TraceEnd, FColor::Red, false, -1.0f, SDPG_World, 3.0f);
			}
		}
	}
}
