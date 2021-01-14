// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
//#include "TicTacToeTile.h"
#include "TicTacToeTileGrid.generated.h"

class ATicTacToeTile;

UCLASS()
class TICTACTOE_API ATicTacToeTileGrid : public AActor
{
	GENERATED_BODY()
	
public:
	//Array of tiles
	ATicTacToeTile *gridArray[9];

	int32 Size;
	int32 TileSpacing;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class ATicTacToeTile> ToSpawn;


public:	
	// Sets default values for this actor's properties
	ATicTacToeTileGrid();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//Checks if the player won
	UFUNCTION(BlueprintCallable)
	int32 VictoryCheck(int chosenTile, bool isPlayerX);

	bool checkNearTiles(int tile1, int tile2, int playerNum);

};
