// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetActor.h"

#include "Net/UnrealNetwork.h"

ATargetActor::ATargetActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bOnAsyncDestroy = false;
	bReplicates = true;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Mesh->SetupAttachment(RootComponent);
	
}

void ATargetActor::BeginPlay()
{
	Super::BeginPlay();
	CaptureValueInterface.SetInterface(this);
	CaptureValueInterface.SetObject(this);
}

void ATargetActor::SetNewAsyncDestroyValue(const bool bNewValue)
{
	bOnAsyncDestroy = bNewValue;
	OnRep_OnAsyncDestroy();
}

void ATargetActor::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ATargetActor, bOnAsyncDestroy);
}

void ATargetActor::OnRep_OnAsyncDestroy()
{
	OnValueChangedDelegate.Broadcast(bOnAsyncDestroy);
}
