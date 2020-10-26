#include "ToggleSphere_Composition.h"

#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "Materials/MaterialInterface.h"
#include "Engine/StaticMesh.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"

#include "Log.h"
#include "TouchyTypes.h"
#include "InteractionComponent.h"

AToggleSphere_Composition::AToggleSphere_Composition(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Note that loading assets in C++ constructors isn't usually a great idea,
	// in part because it creates a hard reference at module load time (i.e. when
	// this class is first loaded, the Engine will block until it loads the
	// referenced assets, and those assets will always remain in memory).
	// Typically you'd want to leave most of the display-only stuff (loading
	// meshes and materials) to the Blueprint; we're not bothering with
	// Blueprints here since this is just a C++ example class.
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMeshFinder(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialOnFinder(TEXT("MaterialInstanceConstant'/Game/Scripts/Materials/M_ToggleSphere_On.M_ToggleSphere_On'"));
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialOffFinder(TEXT("MaterialInstanceConstant'/Game/Scripts/Materials/M_ToggleSphere_Off.M_ToggleSphere_Off'"));

	RootComponent = ObjectInitializer.CreateDefaultSubobject<USceneComponent>(this, TEXT("RootComponent"));

	MeshComponent = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("MeshComponent"));
	MeshComponent->SetCollisionResponseToChannel(ECC_Interaction, ECR_Block);
	MeshComponent->SetStaticMesh(SphereMeshFinder.Object);
	MeshComponent->SetupAttachment(RootComponent);

	InteractionComponent = ObjectInitializer.CreateDefaultSubobject<UInteractionComponent>(this, TEXT("InteractionComponent"));
	InteractionComponent->NativeOnUsed.BindUObject(this, &AToggleSphere_Composition::OnInteractionComponentUsed);

	MaterialOn = MaterialOnFinder.Object;
	MaterialOff = MaterialOffFinder.Object;
}

void AToggleSphere_Composition::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	UpdateMesh();
}

void AToggleSphere_Composition::OnInteractionComponentUsed(APawn* Pawn)
{
	// Write a debug log message (and output it to the screen as well)
	const FString Message = FString::Printf(TEXT("%s used by: %s"), *GetName(), *Pawn->GetName());
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 1.0f, FColor::White, Message);
	UE_LOG(LogTouchyTestActors, Log, TEXT("%s"), *Message);

	bToggledOn = !bToggledOn;
	UpdateMesh();
}

void AToggleSphere_Composition::UpdateMesh()
{
	MeshComponent->SetMaterial(0, bToggledOn ? MaterialOn : MaterialOff);
}
