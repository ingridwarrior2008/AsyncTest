// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AsyncCaptureValueChange.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCaptureValueChangedSignature, AActor*, TargetActor, bool, bNewValueChanged);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCaptureValueFailSignature);


/**
 * AsyncCaptureValueChange Class. A blueprint async node to detect when an actor that inherits from ICaptureValueInterface has changed a bool value. 
 */
UCLASS()
class ASYNCTEST_API UAsyncCaptureValueChange : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
	
public:
	UAsyncCaptureValueChange();

	UFUNCTION(BlueprintCallable, meta=( BlueprintInternalUseOnly="true" ))
	static UAsyncCaptureValueChange* CaptureValueChangeAsync(const TScriptInterface<ICaptureValueInterface>& CaptureValueInterface);
	
	UPROPERTY(BlueprintAssignable)
	FOnCaptureValueChangedSignature OnCompleteDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnCaptureValueFailSignature OnFailDelegate;

private:

	UFUNCTION()
	void OnCaptureValueChange(const bool bNewValue);
	
	UPROPERTY(Transient)
	AActor* TargetActor;
};