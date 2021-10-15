// ⓒFox Tales Studio


#include "LevelMovingPortalVolume.h"

ALevelMovingPortalVolume::ALevelMovingPortalVolume()
{
	OnActorBeginOverlap.AddDynamic(this, &ALevelMovingPortalVolume::OnOverLapBegin);
	OnActorEndOverlap.AddDynamic(this, &ALevelMovingPortalVolume::OnOverLapEnd);
}

void ALevelMovingPortalVolume::BeginPlay()
{
	Super::BeginPlay();
}

void ALevelMovingPortalVolume::OnOverLapBegin(AActor* OverlaappedActor, AActor* OtherActor)
{

}

void ALevelMovingPortalVolume::OnOverLapEnd(AActor* OverlaappedActor, AActor* OtherActor)
{

}

