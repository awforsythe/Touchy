#include "InteractionTrace.h"

#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "DrawDebugHelpers.h"

UInteractionTrace::UInteractionTrace(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	TraceDistance = 100.0f;
}

void UInteractionTrace::Update(UWorld* World, APawn* OwningPawn, ECollisionChannel TraceChannel)
{
	// The caller should supply a valid World and Pawn
	if (World && OwningPawn)
	{
		// Get the player POV: this gives us a world-space ray pointing into the center of the screen
		FVector ViewLocation;
		FRotator ViewRotation;
		OwningPawn->GetActorEyesViewPoint(ViewLocation, ViewRotation);

		// Prepare the input parameters for the line trace
		const FVector& TraceStart = ViewLocation;
		const FVector TraceEnd = TraceStart + (ViewRotation.Vector() * TraceDistance);
		const FCollisionQueryParams QueryParams(TEXT("Interaction"), false, OwningPawn);
		const FCollisionResponseParams ResponseParams(ECR_Block);

		// Run the line trace, seeing if we hit anything that blocks the interaction channel
		if (World->LineTraceSingleByChannel(Hit, TraceStart, TraceEnd, TraceChannel, QueryParams, ResponseParams))
		{
			// If debug drawing is enabled, visualize the hit location and normal
			if (bDebugDraw)
			{
				DrawDebugLine(World, TraceStart, Hit.ImpactPoint, FColor::Green, false, -1.0f, SDPG_World, 3.0f);
				DrawDebugDirectionalArrow(World, Hit.ImpactPoint, Hit.ImpactPoint + Hit.ImpactNormal * 50.0f, 10.0f, FColor::Yellow, false, -1.0f, SDPG_World, 3.0f);
			}
		}
		else
		{
			// If debug drawing is enabled, visualize the extent of the trace
			if (bDebugDraw)
			{
				DrawDebugLine(World, TraceStart, TraceEnd, FColor::Red, false, -1.0f, SDPG_World, 3.0f);
			}
		}
	}
	else
	{
		// If we were called with invalid parameters, clear the blocking hit flag to indicate that we have no hit result
		Hit.bBlockingHit = false;
	}
}
