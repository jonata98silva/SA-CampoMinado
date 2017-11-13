// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItensColetaveis.h"
#include "Bomba.generated.h"

UCLASS()
class CMSA_API ABomba : public AItensColetaveis
{
	GENERATED_BODY()

private:

	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)override;

};
