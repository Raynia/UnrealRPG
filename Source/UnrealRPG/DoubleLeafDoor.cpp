// ⓒFox Tales Studio


#include "DoubleLeafDoor.h"

// Sets default values
ADoubleLeafDoor::ADoubleLeafDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 도어 프레임 컴포넌트 설정
	DoorFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorFrame"));
	DoorFrame->SetupAttachment(RootComponent);
	DoorFrame->SetMobility(EComponentMobility::Static);

	// 좌측 문 컴포넌트 설정
	LeftDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeftDoor"));
	LeftDoor->SetupAttachment(DoorFrame);
	DoorFrame->SetMobility(EComponentMobility::Movable);

	// 우측 문 컴포넌트 설정
	RightDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RightDoor"));
	RightDoor->SetupAttachment(DoorFrame);
	DoorFrame->SetMobility(EComponentMobility::Movable);

	// 화살표 컴포넌트 설정
	Arrow1 = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow1"));
	Arrow1->SetupAttachment(DoorFrame);
	DoorFrame->SetMobility(EComponentMobility::Static);

	// 상호작용을 위한 구체 컴포턴트 설정
	Sphere1 = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere1"));
	Sphere1->InitSphereRadius(500.0f);
	Sphere1->SetupAttachment(RootComponent);
	//Sphere1->OnComponentBeginOverlap.AddDynamic(this, &ADoubleLeafDoor::OnOverlabBegin);
	//Sphere1->OnComponentEndOverlap.AddDynamic(this, &ADoubleLeafDoor::OnOverlabEnd);
}

// Called when the game starts or when spawned
void ADoubleLeafDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADoubleLeafDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADoubleLeafDoor::OnOverlabBegin(UPrimitiveComponent* OverlapComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		DoorOpen(LeftDoor, DoorPosition::Left);
		DoorOpen(RightDoor, DoorPosition::Right);
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("Open"));
	}
}

void ADoubleLeafDoor::OnOverlabEnd(UPrimitiveComponent* OverlapComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		DoorClose(LeftDoor, DoorPosition::Left);
		DoorClose(RightDoor, DoorPosition::Right);
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("Close"));
	}
}

void ADoubleLeafDoor::DoorOpen(UStaticMeshComponent* TargetComponent, int DoorPosition)
{
	FRotator NewRotation = TargetComponent->GetRelativeRotation();
	NewRotation.Yaw += (DoorRotateDegree * DoorPosition);
	TargetComponent->SetRelativeRotation(NewRotation);
}

void ADoubleLeafDoor::DoorClose(UStaticMeshComponent* TargetComponent, int DoorPosition)
{
	FRotator NewRotation = TargetComponent->GetRelativeRotation();
	NewRotation.Yaw += ((-DoorRotateDegree) * DoorPosition);
	TargetComponent->SetRelativeRotation(NewRotation);
}