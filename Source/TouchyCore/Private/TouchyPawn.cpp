#include "TouchyPawn.h"

ATouchyPawn::ATouchyPawn(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.DoNotCreateDefaultSubobject(ADefaultPawn::MeshComponentName))
{
}
