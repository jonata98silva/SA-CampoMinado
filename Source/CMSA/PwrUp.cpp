// Fill out your copyright notice in the Description page of Project Settings.

#include "PwrUp.h"
#include "Personagem.h"

void APwrUp::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if (OtherActor != nullptr && OtherActor->IsA(APersonagem::StaticClass())) {
		APersonagem* Personagem = Cast<APersonagem>(OtherActor);
		Personagem->PoderPedra();
		Destroy();
	}
}


