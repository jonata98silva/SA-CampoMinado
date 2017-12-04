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
	void Explodiu();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Life")
		int Vida;

	int GetGanhou();
	void SetGanhou(bool Value);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ganhou")
		bool Ganhou;

private:

	UPROPERTY(EditAnywhere)
		class UPaperFlipbookComponent* Sprite;
	UPROPERTY(EditAnywhere)
		class UPaperSprite* Personagem;

	

	int PosiPersonagemY;
	int PosiPersonagemX;
	
};