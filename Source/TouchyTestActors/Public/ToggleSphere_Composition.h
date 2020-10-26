#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "ToggleSphere_Composition.generated.h"

UCLASS()
class AToggleSphere_Composition : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	class UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	class UInteractionComponent* InteractionComponent;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Test")
	bool bToggledOn;

private:
	UPROPERTY()
	class UMaterialInterface* MaterialOff;

	UPROPERTY()
	class UMaterialInterface* MaterialOn;

public:
	AToggleSphere_Composition(const FObjectInitializer& ObjectInitializer);
	virtual void OnConstruction(const FTransform& Transform) override;

private:
	void OnInteractionComponentUsed(class APawn* Pawn);
	void UpdateMesh();
};
