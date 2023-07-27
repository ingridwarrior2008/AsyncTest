// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CaptureValueInterface.h"
#include "GameFramework/Actor.h"
#include "TargetActor.generated.h"

/**
 * Target Actor Class. It will dispatch an event when the value bOnAsyncDestroy changes.
 */
UCLASS()
class ASYNCTEST_API ATargetActor : public AActor, public ICaptureValueInterface
{
	GENERATED_BODY()
	
public:	
	ATargetActor();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "TargetActor", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> Mesh;

#pragma region ICaptureValueInterface

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetNewAsyncDestroyValue(const bool bNewValue);
	
	virtual bool GetCaptureValue() override { return bOnAsyncDestroy; }
	virtual FOnValueChangedSignature& GetValueChangedDelegate() override { return OnValueChangedDelegate; }

	UFUNCTION(BlueprintCallable)
	TScriptInterface<ICaptureValueInterface> GetCaptureValueInterface() const { return CaptureValueInterface; }

protected:
	UPROPERTY(Transient, ReplicatedUsing = OnRep_OnAsyncDestroy)
	bool bOnAsyncDestroy;

	UPROPERTY(BlueprintAssignable)
	FOnValueChangedSignature OnValueChangedDelegate;

private:
	UPROPERTY(transient)
	TScriptInterface<ICaptureValueInterface> CaptureValueInterface;

	UFUNCTION()
	void OnRep_OnAsyncDestroy();

#pragma endregion ICaptureValueInterface
	
};
