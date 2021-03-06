// Fill out your copyright notice in the Description page of Project Settings.

#include "Casa.h"
#include "Components/BoxComponent.h"
#include "PaperSpriteComponent.h"
#include "Personagem.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Bomba.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"

// Sets default values
ACasa::ACasa()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	

	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Sprite"));
	Sprite->OnInputTouchBegin.AddDynamic(this, &ACasa::OnTouchBegin);
	Sprite->SetupAttachment(RootComponent);
	
	ConstructorHelpers::FObjectFinder<UClass> ActorQueroSpawnar(TEXT("Blueprint'/Game/Blueprint/ExplosionEffectBP.ExplosionEffectBP_C'"));
	if (ActorQueroSpawnar.Succeeded()) { ExpEffect = Cast<UClass>(ActorQueroSpawnar.Object); }

	ConstructorHelpers::FObjectFinder<UClass> SpawnarWin(TEXT("Blueprint'/Game/Blueprint/ExplosionEffectBP.ExplosionEffectBP_C'"));
	if (SpawnarWin.Succeeded()) { ExpEffect = Cast<UClass>(SpawnarWin.Object); }



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

int ACasa::GetPertLinha()
{
	return PertLinha;
}

void ACasa::SetPertLinha(int Value)
{
	LinhaP = Value;
}

int ACasa::GetLinhaX()
{
	return LinhaX;
}

void ACasa::SetLinhaX(int Value)
{
	LinhaX = Value;
}

void ACasa::OnTouchBegin(ETouchIndex::Type Type, UPrimitiveComponent * TouchedComponent)
{
	UWorld* World = GetWorld();
	if (World) {
		UE_LOG(LogTemp, Warning, TEXT("NUMCASA %d"), NumCasa);
		if (Liberou) {
			int PosX = User->GetPosiPersonagemX() - LinhaX;
			int PosY = User->GetPosiPersonagemY() - LinhaP;
			if (PosX >= -1 && PosX <= 1 && PosY >= -1 && PosY <= 1) {
				User->SetPosiPersonagemY(LinhaP);
				User->SetPosiPersonagemX(LinhaX);
				User->SetActorLocation(GetActorLocation());
				SetActorHiddenInGame(true);
				
				if (Index >= 1) {
					FActorSpawnParameters SpawnParameters;
					World->SpawnActor<ABomba>(ExpEffect, GetActorLocation(), GetActorRotation(), SpawnParameters);
					User->Explodiu();
					
				}
				if (NumCasa == 10 || NumCasa == 21 || NumCasa == 32 || NumCasa == 43 || NumCasa == 54 || NumCasa == 65 || NumCasa == 76 || NumCasa == 87) {
					if (Index != 1) {
						User->SetGanhou(true);
						UE_LOG(LogTemp, Warning, TEXT("GANHOU!!!!"));
						FActorSpawnParameters SpawnParameters;
						World->SpawnActor<ABomba>(ExpEffect, GetActorLocation(), GetActorRotation(), SpawnParameters);
					}
					else {
						User->Explodiu();
					}
					
				}

			}
		}
		
	}
}

void ACasa::ReturnBool1()
{
	UE_LOG(LogTemp, Warning, TEXT("Vc Perdeu!!"));
}

void ACasa::Liberar(bool Value)
{
	if (Value) {
		Liberou = true;
	}
}

void ACasa::InitPerson(APersonagem* Person)
{
	User = Person;
}

int ACasa::GetNumCasa()
{
	return NumCasa;
}

void ACasa::SetNumCasa(int Value)
{
	NumCasa = Value;
}


