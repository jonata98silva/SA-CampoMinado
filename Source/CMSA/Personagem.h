// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Personagem.generated.h"

UCLASS()
class CMSA_API APersonagem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APersonagem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:

	int GetVida();
	void SetVida(int Value);
	int GetPosiPersonagemX();
	void SetPosiPersonagemX(int Value);
	int GetPosiPersonagemY();
	void SetPosiPersonagemY(int Value);

	//int GetPedras();
	//void SetPedras(int Value);
	void Explodiu();
	//void Coletou();
	//void PoderPedra();

	

private:

	UPROPERTY(EditAnywhere)
		class UPaperFlipbookComponent* Sprite;
	UPROPERTY(EditAnywhere)
		class UPaperSprite* Personagem;

	int Vida;
	//int Pedras;
	//bool PowerUp1;
	//Variavel pra localização do personagem tipo fvetor
	int PosiPersonagemY;
	int PosiPersonagemX;
	
};
