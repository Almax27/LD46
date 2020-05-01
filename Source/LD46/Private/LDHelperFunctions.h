// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "LDHelperFunctions.generated.h"

/**
 * 
 */
UCLASS()
class ULDHelperFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	static bool DepenetrateActorAt(AActor* Actor, FVector Location, FRotator Rotation, FVector& Adjustment);

	UFUNCTION(BlueprintCallable)
	static bool DepenetrateActor(AActor* Actor, FVector& Adjustment);

	UFUNCTION(BlueprintCallable, Category = "Sort")
    static void SortActorsByDistance(const FVector& Location, UPARAM(Ref) TArray<AActor*>& ActorsToSort, bool AccendingOrder, TArray<float>& OutDistances);
	
};
