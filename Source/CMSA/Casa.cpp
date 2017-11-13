// Fill out your copyright notice in the Description page of Project Settings.

#include "Casa.h"
#include "Components/BoxComponent.h"
#include "PaperSpriteComponent.h"
#include "Personagem.h"


// Sets default values
ACasa::ACasa()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Sprite"));
	Sprite->SetupAttachment(CollisionComp);
	RootComponent = Sprite;



}

// Called when the game starts or when spawned
void ACasa::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACasa::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACasa::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
}
void ACasa::SetCampo(Campo * NewCampo)
{
	Campo = NewCampo;
}

Campo * ACasa::GetCampo()
{
	return Campo;
}

