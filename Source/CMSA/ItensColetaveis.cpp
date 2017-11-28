// Fill out your copyright notice in the Description page of Project Settings.

#include "ItensColetaveis.h"
#include "Components/SphereComponent.h"
#include "PaperFlipbookComponent.h"


// Sets default values
AItensColetaveis::AItensColetaveis()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComp"));
	CollisionComp->SetCollisionProfileName("OverlapAllDynamic");
	CollisionComp->bGenerateOverlapEvents = true;
	CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &AItensColetaveis::OnOverlapBegin);
	RootComponent = CollisionComp;

	Sprite = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Sprite"));
	Sprite->SetupAttachment(CollisionComp);

}

// Called when the game starts or when spawned
void AItensColetaveis::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItensColetaveis::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItensColetaveis::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("itc"));
	}

