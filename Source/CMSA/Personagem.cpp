// Fill out your copyright notice in the Description page of Project Settings.

#include "Personagem.h"
#include "PaperFlipbookComponent.h"


// Sets default values
APersonagem::APersonagem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Sprite = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Sprite"));
	RootComponent = Sprite;
	Vida = 3;

}

// Called when the game starts or when spawned
void APersonagem::BeginPlay()
{
	Super::BeginPlay();
	//PowerUp1 = false;
	PosiPersonagemY = -1;
	
}

// Called every frame
void APersonagem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int APersonagem::GetVida()
{
	return Vida;
}

void APersonagem::SetVida(int Value)
{
	Vida = Value;
}

int APersonagem::GetPosiPersonagemX()
{
	return PosiPersonagemX;
}

void APersonagem::SetPosiPersonagemX(int Value)
{
	PosiPersonagemX = Value;
}

int APersonagem::GetPosiPersonagemY()
{
	return PosiPersonagemY;
}

void APersonagem::SetPosiPersonagemY(int Value)
{
	PosiPersonagemY = Value;
}

void APersonagem::Explodiu()
{
	UE_LOG(LogTemp, Warning, TEXT("PERSONAGEM EXPLODIU"));
	Vida--;
}