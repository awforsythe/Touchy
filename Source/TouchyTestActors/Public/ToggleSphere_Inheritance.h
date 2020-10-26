#pragma once

#include "CoreMinimal.h"
#include "InteractibleActor.h"

#include "ToggleSphere_Inheritance.generated.h"

UCLASS()
class AToggleSphere_Inheritance : public AInteractibleActor
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	class UStaticMeshComponent* MeshComponent;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Test")
	bool bToggledOn;

private:
	UPROPERTY()
	class UMaterialInterface* MaterialOff;

	UPROPERTY()
	class UMaterialInterface* MaterialOn;

public:
	AToggleSphere_Inheritance(const FObjectInitializer& ObjectInitializer);
	virtual void OnConstruction(const FTransform& Transform) override;

	virtual void Used(class APawn* Pawn) override;

private:
	void UpdateMesh();
};
