// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CaptureValueInterface.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnValueChangedSignature, bool, bNewValue);

UINTERFACE(MinimalAPI,BlueprintType, meta = (CannotImplementInterfaceInBlueprint))
class UCaptureValueInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * CaptureValue Interface
 */
class ASYNCTEST_API ICaptureValueInterface
{
	GENERATED_BODY()

public:

	virtual bool GetCaptureValue()  = 0;
	virtual FOnValueChangedSignature& GetValueChangedDelegate() = 0;
};
