// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Casa.generated.h"

UCLASS()
class CMSA_API ACasa : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACasa();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	

	int GetIndex();
	void SetIndex(int Value);
	void AumentaIndex();
	int GetPertLinha();
	void SetPertLinha(int Value);
	int GetLinhaX();
	void SetLinhaX(int Value);
	UFUNCTION()
		void Linha(int Value);

	//UFUNCTION()
	//	void CondVitoria();
	
	
private:

	UPROPERTY(EditAnywhere)
		class UPaperSpriteComponent* Sprite;

	UPROPERTY(EditAnywhere)
		class UPaperSprite* OpenCard;

	UPROPERTY(EditAnywhere)
		class UPaperSprite*ClosedCard;

	
	UFUNCTION()
	 void OnTouchBegin(ETouchIndex::Type Type, UPrimitiveComponent* TouchedComponent);

	int Index;
	int Boom;
	int Explosao;
	
	int Derrota;
	int PertLinha;
	int Num;
	int Val;

	int LinhaP;
	int LinhaX;

	UFUNCTION(BlueprintCallable, Category = "Minha")
		void ReturnBool1(int Value);

	
	
};
