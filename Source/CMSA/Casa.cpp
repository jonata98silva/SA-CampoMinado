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
	UWorld* World = GetWorld();
	if (World) {
		TArray<AActor*> Personagem;
		UGameplayStatics::GetAllActorsOfClass(World, APersonagem::StaticClass(), Personagem);
		if (Personagem.Num() >= 1) {
			APersonagem* Persona = Cast<APersonagem>(Personagem[0]);
			Persona->SetActorLocation(GetActorLocation());
			UE_LOG(LogTemp, Warning, TEXT("Posição %s"), *Persona->GetActorLocation().ToString());
			if (Index == 1) {
				Persona->Explodiu();
				if (Persona->GetVida() == 0) {
					//UE_LOG(LogTemp, Warning, TEXT("Vc Perdeu!!"));
					Derrota = 1;
					ReturnBool1(Derrota);					
				}
			}
		}
	}
	SetActorHiddenInGame(true);
}

void ACasa::ReturnBool1(int Value)
{
	if (Value == 1) {
		UE_LOG(LogTemp, Warning, TEXT("Vc Perdeu!!"));
		GetWorld()->GetFirstPlayerController()->ConsoleCommand("Exit");
		
		
	}
	
}

	
		


