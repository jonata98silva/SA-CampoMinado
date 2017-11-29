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
	PowerUp1 = false;
	
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

int APersonagem::GetPedras()
{
	return Pedras;
}

void APersonagem::SetPedras(int Value)
{
	Pedras = Value;
}

void APersonagem::Explodiu()
{
	UE_LOG(LogTemp, Warning, TEXT("PERSONAGEM EXPLODIU"));
	Vida--;
}

void APersonagem::Coletou()
{
	if (Pedras < 5) {
		Pedras++;
	}
	if (PowerUp1) {
		if (Pedras < 7) {
			Pedras++;
		}
	}
}

void APersonagem::PoderPedra()
{
	PowerUp1 = true;
	Pedras = 7;
}

