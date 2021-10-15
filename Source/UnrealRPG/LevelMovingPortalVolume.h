// ⓒFox Tales Studio

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "LevelMovingPortalVolume.generated.h"

/**
 * 
 */
UCLASS()
class UNREALRPG_API ALevelMovingPortalVolume : public ATriggerVolume
{
	GENERATED_BODY()

public:
	ALevelMovingPortalVolume();
	
protected:
	virtual void BeginPlay() override;

public:

	UFUNCTION()
	void OnOverLapBegin(AActor* OverlaappedActor, AActor* OtherActor);

	UFUNCTION()
	void OnOverLapEnd(AActor* OverlaappedActor, AActor* OtherActor);
};
