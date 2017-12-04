// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPawn.h"
#include "Camera/CameraComponent.h"
#include "Campo.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Casa.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Casa.h"
#include "Personagem.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Public/TimerManager.h"



// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->ProjectionMode = ECameraProjectionMode::Orthographic;
	Camera->OrthoWidth = 2048.0f;
	Camera->SetupAttachment(RootComponent);
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	

	ConstructorHelpers::FObjectFinder<UClass> CasaBP(
		TEXT("Blueprint'/Game/Blueprint/MyCasa.MyCasa_C'"));

	ConstructorHelpers::FObjectFinder<UClass> PersonagemBP(
		TEXT("Blueprint'/Game/Blueprint/PersonagemBP.PersonagemBP_C'"));

	if (PersonagemBP.Succeeded()) {
		UE_LOG(LogTemp, Warning, TEXT("VERIFICOU"));
		Personagem = Cast<UClass>(PersonagemBP.Object);
	}

	if (CasaBP.Succeeded()) {
		UE_LOG(LogTemp, Warning, TEXT("Verificou"));
		Casa = Cast<UClass>(CasaBP.Object);
	}
	

}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();

	if (Casa) {
		UWorld* World = GetWorld();

		if (World) {
			FActorSpawnParameters SpawnParameters;
			APersonagem* Persona = World->SpawnActor<APersonagem>(Personagem, FVector(0.0f, 0.0f, -45.0f), FRotator::ZeroRotator, SpawnParameters);
			
			if (Persona) {

				for (int x = 0; x < 8; x++) {
					TArray<ACasa*> NewCol;

					for (int y = 0; y < 11; y++) {
						FActorSpawnParameters SpawnParameters;
						ACasa* NewCasa = World->SpawnActor<ACasa>(Casa, FVector(x * 53.0f, 0.0f, y * 49.0f), FRotator::ZeroRotator, SpawnParameters);
						NewCol.Add(NewCasa);
						NewCasa->SetPertLinha(y);
						NewCasa->SetLinhaX(x);
						NewCasa->SetNumCasa(NewCasa->GetNumCasa() + CsaNum);
						UE_LOG(LogTemp, Warning, TEXT("NUMERO DA CASA %d"), NewCasa->GetNumCasa());
						NewCasa->InitPerson(Persona);

						int R = FMath::RandRange(0, 10);

						if (R == 3 && ContBombas == 20) {
							NewCasa->AumentaIndex();
							ContBombas++;
							NewCasa->SetActorHiddenInGame(true);
						}
						CsaNum++;
					}
					Matriz.Add(NewCol);
				}
				GetWorldTimerManager().SetTimer(Time, this, &AMyPawn::EsconderBombas, 3.0f, false);		
			}
		}
	}
}


// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void AMyPawn::EsconderBombas()
{
	UWorld* World = GetWorld();
	if (World) {
		for (int i = 0; i < Matriz.Num(); i++) {
			for (int j = 0; j < Matriz[i].Num(); j++) {
				Matriz[i][j]->SetActorHiddenInGame(false);
				Matriz[i][j]->Liberar(true);
			}
		}
	}
}


