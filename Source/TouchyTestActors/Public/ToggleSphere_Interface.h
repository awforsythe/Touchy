#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactible.h"

#include "ToggleSphere_Interface.generated.h"

UCLASS()
class AToggleSphere_Interface : public AActor, public IInteractible
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
	AToggleSphere_Interface(const FObjectInitializer& ObjectInitializer);
	virtual void OnConstruction(const FTransform& Transform) override;

	virtual void Used_Implementation(class APawn* Pawn) override;

private:
	void UpdateMesh();
};
