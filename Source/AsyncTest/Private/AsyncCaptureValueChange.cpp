// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncCaptureValueChange.h"

#include "CaptureValueInterface.h"

UAsyncCaptureValueChange::UAsyncCaptureValueChange()
{
}

UAsyncCaptureValueChange* UAsyncCaptureValueChange::CaptureValueChangeAsync(const TScriptInterface<ICaptureValueInterface>& CaptureValueInterface)
{ 
	UAsyncCaptureValueChange* CaptureValueChange = NewObject<UAsyncCaptureValueChange>();
	if (!IsValid(CaptureValueChange))
	{
		return nullptr;
	}

	AActor* FoundTargetActor = Cast<AActor>(CaptureValueInterface.GetObject());
	if (!CaptureValueInterface.GetInterface() || !IsValid(FoundTargetActor))
	{
		CaptureValueChange->OnFailDelegate.Broadcast();
		return CaptureValueChange;
	}
	
	CaptureValueChange->TargetActor = FoundTargetActor;
	CaptureValueInterface.GetInterface()->GetValueChangedDelegate().AddDynamic(CaptureValueChange, &UAsyncCaptureValueChange::OnCaptureValueChange);

	return CaptureValueChange;
}

void UAsyncCaptureValueChange::OnCaptureValueChange(const bool bNewValue)
{
	OnCompleteDelegate.Broadcast(TargetActor, bNewValue);
}
