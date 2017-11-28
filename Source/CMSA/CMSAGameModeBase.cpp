// Fill out your copyright notice in the Description page of Project Settings.

#include "CMSAGameModeBase.h"
#include "CMSAPlayerController.h"



ACMSAGameModeBase::ACMSAGameModeBase() {
	PlayerControllerClass = ACMSAPlayerController::StaticClass();
}


