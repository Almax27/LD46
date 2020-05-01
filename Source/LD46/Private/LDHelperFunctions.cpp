// Fill out your copyright notice in the Description page of Project Settings.


#include "LDHelperFunctions.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"

bool ULDHelperFunctions::DepenetrateActorAt(AActor* Actor, FVector Location, FRotator Rotation, FVector& Adjustment)
{
	if (Actor && Actor->GetWorld())
	{
		return Actor->GetWorld()->EncroachingBlockingGeometry(Actor, Location, Rotation, &Adjustment);
	}
	return false;
}

bool ULDHelperFunctions::DepenetrateActor(AActor* Actor, FVector& Adjustment)
{
	if (Actor && Actor->GetWorld())
	{
		return Actor->GetWorld()->EncroachingBlockingGeometry(Actor, Actor->GetActorLocation(), Actor->GetActorRotation(), &Adjustment);
	}
	return false;
}

void ULDHelperFunctions::SortActorsByDistance(const FVector& Location, TArray<AActor*>& ActorsToSort, bool AccendingOrder, TArray<float>& OutDistances)
{
	if (ActorsToSort.Num() == 0)
	{
		return;
	}

	//Remove invalid Actors
	ActorsToSort.Remove(nullptr);

	//Initialise output distances array
	OutDistances.SetNumZeroed(ActorsToSort.Num(), true);

	//Precalculate distances
	TMap<const AActor*, float> Distances;
	Distances.Reserve(ActorsToSort.Num());
	for (const auto Actor : ActorsToSort)
	{
		Distances.Add(Actor, FVector::Dist(Location, Actor->GetActorLocation()));
	}

	//Sort Actors
	ActorsToSort.StableSort([Location, AccendingOrder, &Distances](const AActor& A, const AActor& B)
	{
		return Distances[&A] < Distances[&B];
	});

	//Gather cached distances
	for (int i = 0; i < Distances.Num(); ++i)
	{
		OutDistances[i] = Distances[ActorsToSort[i]];
	}
}