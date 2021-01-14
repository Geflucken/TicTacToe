// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TicTacToeTile.generated.h"

UCLASS()
class TICTACTOE_API ATicTacToeTile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATicTacToeTile();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 TileState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 TileNum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class ATicTacToeTileGrid* OwningGrid;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
