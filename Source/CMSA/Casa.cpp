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
	Val = 1;
	
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
	UE_LOG(LogTemp, Warning, TEXT("LinhaP %d"), LinhaP);
	//UE_LOG(LogTemp, Warning, TEXT("VALUE %d"), Value);
	////PertLinha = Value;
	//UE_LOG(LogTemp, Warning, TEXT("PertLinha Vamover %d"), PertLinha);
	//Num = Value;
	//Linha(Value);
	
}

int ACasa::GetLinhaX()
{
	return LinhaX;
}

void ACasa::SetLinhaX(int Value)
{
	LinhaX = Value;
	UE_LOG(LogTemp, Warning, TEXT("LinhaX %d"), LinhaX);
}

void ACasa::OnTouchBegin(ETouchIndex::Type Type, UPrimitiveComponent * TouchedComponent)
{
	
	//UE_LOG(LogTemp, Warning, TEXT("NUM %d "), Num);
	//UE_LOG(LogTemp, Warning, TEXT("PertLinha valor %d "), PertLinha);
	//UE_LOG(LogTemp, Warning, TEXT("Val %d "), Val);
	//if (Val - 1 == Num) {
	
		UWorld* World = GetWorld();
		if (World) {
			TArray<AActor*> Personagem;
			UGameplayStatics::GetAllActorsOfClass(World, APersonagem::StaticClass(), Personagem);
			if (Personagem.Num() >= 1) {
				APersonagem* Persona = Cast<APersonagem>(Personagem[0]);
				if (Persona->GetPosiPersonagemY() == LinhaP  || Persona->GetPosiPersonagemY() == LinhaP - 1
					|| LinhaP < Persona->GetPosiPersonagemY()) {
					UE_LOG(LogTemp, Warning, TEXT("MOVE LINHAP"));
					UE_LOG(LogTemp, Warning, TEXT("POSI Linha %d"), Persona->GetPosiPersonagemY());
					Persona->SetPosiPersonagemY(LinhaP);
					Persona->SetActorLocation(GetActorLocation());
					int PosiAtual = Persona->GetPosiPersonagemX();
					if (Persona->GetPosiPersonagemX() == LinhaX || Persona->GetPosiPersonagemX() == LinhaX - 1
						|| LinhaX < Persona->GetPosiPersonagemX()){
						UE_LOG(LogTemp, Warning, TEXT("MOVE COLUNAX"));
						UE_LOG(LogTemp, Warning, TEXT("POSI COLUNA %d"), Persona->GetPosiPersonagemX());
						Persona->SetActorLocation(GetActorLocation());
						Persona->SetPosiPersonagemX(LinhaX);
						Persona->SetPosiPersonagemY(LinhaP);
					//UE_LOG(LogTemp, Warning, TEXT("Posição %s"), *Persona->GetActorLocation().ToString());
					SetActorHiddenInGame(true);
					}
					//Persona->SetActorLocation(GetActorLocation());					
				}
				
				if (Index == 1) {
					Persona->Explodiu();
					Index = 0;
					if (Persona->GetVida() == 0) {
						Derrota = 1;
						ReturnBool1(Derrota);
					}
				}
				
			}


			//}
			//else {
			//	UE_LOG(LogTemp, Warning, TEXT("NAO DEU"));
			//}

	}	
}

void ACasa::ReturnBool1(int Value)
{
	if (Value == 1) {
		UE_LOG(LogTemp, Warning, TEXT("Vc Perdeu!!"));
		GetWorld()->GetFirstPlayerController()->ConsoleCommand("Exit");	
	}
}

void ACasa::Linha(int Value)
{
	//UE_LOG(LogTemp, Warning, TEXT("VALUE2 %d"), Value);
	//PertLinha = Value += 1;
	//Val = Value += 1;
	//UE_LOG(LogTemp, Warning, TEXT("PertLinha %d"), PertLinha);
}

/*void AMyPawn::CondVitoria()
{
	if (LinhaX == 10)
}
*/
	
		


