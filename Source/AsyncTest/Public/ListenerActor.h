// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ListenerActor.generated.h"

/**
 * Listener Actor Class. It will implement the async node in the blueprint to check when the target actor value changes.
 */
UCLASS()
class ASYNCTEST_API AListenerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AListenerActor();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ListenerActor", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> Mesh;
};
