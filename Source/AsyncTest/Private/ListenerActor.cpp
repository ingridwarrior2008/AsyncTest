// Fill out your copyright notice in the Description page of Project Settings.


#include "ListenerActor.h"


AListenerActor::AListenerActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Mesh->SetupAttachment(RootComponent);
}


void AListenerActor::BeginPlay()
{
	Super::BeginPlay();
	
}
