// Fill out your copyright notice in the Description page of Project Settings.

#include "Campo.h"
#include "Components/SceneComponent.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Casa.h"
#include "Runtime/Engine/Classes/Engine/World.h"


// Sets default values
ACampo::ACampo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	ConstructorHelpers::FObjectFinder<UClass> CasaBP(
		TEXT("Blueprint'/Game/Blueprint/Casa.Casa_C'"));

	if (CasaBP.Succeeded()) {
		UE_LOG(LogTemp, Warning, TEXT("Verificou"));
		Casa = Cast<UClass>(CasaBP.Object);
	}


}

// Called when the game starts or when spawned
void ACampo::BeginPlay()
{
	Super::BeginPlay();

	for (int x = 0; x < 9; x++) {
		UE_LOG(LogTemp, Warning, TEXT("Primeiro FOR"));
		TArray<ACasa*> NewCol;
		for (int y = 0; y < 9; y++) {
			UE_LOG(LogTemp, Warning, TEXT("Segundo FOR"));
			UWorld* World = GetWorld();
			if (Casa) {
				UE_LOG(LogTemp, Warning, TEXT("Verificou a CasaBP"));
				if (World) {
					UE_LOG(LogTemp, Warning, TEXT("Verificou o World e espalnou"));
					FActorSpawnParameters SpawnParameters;
					ACasa* NewCasa = World->SpawnActor<ACasa>(Casa, FVector( x * 62.0f, 0.0f, y * 56.0f),
						FRotator::ZeroRotator, SpawnParameters);;
					NewCol.Add(NewCasa);
					
				}
			}
		}
		Matriz.Add(NewCol);
	}
}
// Called every frame
void ACampo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACampo::OnTouchBegin(ETouchIndex::Type Type, UPrimitiveComponent * TouchedComponent)
{
	UE_LOG(LogTemp, Warning, TEXT("OnTouchBegin"));
}

