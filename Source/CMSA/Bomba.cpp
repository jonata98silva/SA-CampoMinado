// Fill out your copyright notice in the Description page of Project Settings.

#include "Bomba.h"
#include "Personagem.h"
#include "PaperFlipbookComponent.h"


ABomba::ABomba() {

	PrimaryActorTick.bCanEverTick = true;

	Flipbook = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Sprite"));
	Flipbook->SetLooping(false);
	RootComponent = Flipbook;
	
}

void ABomba::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABomba::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!Flipbook->IsPlaying()) {
		Destroy();
	}
}
