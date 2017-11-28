// Fill out your copyright notice in the Description page of Project Settings.

#include "Casa.h"
#include "Components/BoxComponent.h"
#include "PaperSpriteComponent.h"
#include "Personagem.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"


// Sets default values
ACasa::ACasa()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	

	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Sprite"));
	Sprite->OnInputTouchBegin.AddDynamic(this, &ACasa::OnTouchBegin);
	RootComponent = Sprite;
	




}

// Called when the game starts or when spawned
void ACasa::BeginPlay()
{
	Super::BeginPlay();
	if (ClosedCard != NULL) {
		Sprite->SetSprite(ClosedCard);
	}
	
}

// Called every frame
void ACasa::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



int ACasa::GetIndex()
{
	return Index;
}

void ACasa::SetIndex(int Value)
{
	Index = Value;
}

void ACasa::AumentaIndex()
{
	Index++;
}


void ACasa::OnTouchBegin(ETouchIndex::Type Type, UPrimitiveComponent * TouchedComponent)
{
	UE_LOG(LogTemp, Warning, TEXT("TOCOU NA CARTA"));
	if (Index == 1) {
		UE_LOG(LogTemp, Warning, TEXT("If Index"));
		UWorld* World = GetWorld();
		if (World) {
			TArray<AActor*> Personagem;
			UGameplayStatics::GetAllActorsOfClass(World, APersonagem::StaticClass(), Personagem);
			UE_LOG(LogTemp, Warning, TEXT("TArray %d"), Personagem.Num());
			if (Personagem.Num() >= 1) {
				APersonagem* Persona = Cast<APersonagem>(Personagem[0]);
				Persona->Explodiu();
			}
		}
	}
	Destroy();
}
	
		


