// Fill out your copyright notice in the Description page of Project Settings.


#include "TicTacToeTileGrid.h"
#include "TicTacToeTile.h"

// Sets default values
ATicTacToeTileGrid::ATicTacToeTileGrid()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Size = 3;
	TileSpacing = 110.f;
}

// Called when the game starts or when spawned
void ATicTacToeTileGrid::BeginPlay()
{
	Super::BeginPlay();

	const int NumOfBlocks = Size * Size;

	for (int32 TileIndex = 0; TileIndex < NumOfBlocks; TileIndex++)
	{
		const float XOffset = (TileIndex / Size) * TileSpacing;
		const float YOffset = (TileIndex % Size) * TileSpacing;
		int xInt = int(XOffset);
		int yInt = int(YOffset);

		const FVector TileLocation = FVector(XOffset, YOffset, 0.f) + GetActorLocation();

		//Spawn Tile
		if (ToSpawn)
		{
			ATicTacToeTile *newTile = GetWorld()->SpawnActor<ATicTacToeTile>(ToSpawn, TileLocation, FRotator(0.f, 0.f, 0.f));
			gridArray[TileIndex] = newTile;
			
			// Tell the block about its owner
			if (newTile != nullptr)
			{
				newTile->OwningGrid = this;
				newTile->TileNum = TileIndex;
			}
		}
	}

	
}

// Called every frame
void ATicTacToeTileGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int32 ATicTacToeTileGrid::VictoryCheck(int chosenTile, bool isPlayerX)
{
	int playerNum;

	//Save the state a tile has if it belongs to the current player
	if (isPlayerX)
	{
		playerNum = 1;
	}else
	{
		playerNum = 2;
	}

	//Check if the current player has won 
	switch (chosenTile)
	{
	case 0:
		if (checkNearTiles(3, 6, playerNum) || checkNearTiles(1,2, playerNum)||checkNearTiles(4,8, playerNum))
		{
			return playerNum;
		}
		break;
	
	case 1:
		if (checkNearTiles(4, 7, playerNum) || checkNearTiles(0, 2, playerNum))
		{
			return playerNum;
		}
		break;

	case 2:
		if (checkNearTiles(5, 8, playerNum) || checkNearTiles(1, 0, playerNum) || checkNearTiles(4, 6, playerNum))
		{
			return playerNum;
		}
		break;

	case 3:
		if (checkNearTiles(0, 6, playerNum) || checkNearTiles(4, 5, playerNum))
		{
			return playerNum;
		}
		break;

	case 4:
		if (checkNearTiles(1, 7, playerNum) || checkNearTiles(3, 5, playerNum) || checkNearTiles(0, 8, playerNum) || checkNearTiles(2, 6, playerNum))
		{
			return playerNum;
		}

		break;

	case 5:
		if (checkNearTiles(3, 4, playerNum) || checkNearTiles(2, 8, playerNum))
		{
			return playerNum;
		}

		break;

	case 6:
		if (checkNearTiles(7, 8, playerNum) || checkNearTiles(3, 0, playerNum) || checkNearTiles(4, 2, playerNum))
		{
			return playerNum;
		}
		break;

	case 7:
		if (checkNearTiles(8, 6, playerNum) || checkNearTiles(4, 1, playerNum))
		{
			return playerNum;
		}
		break;

	case 8:
		if (checkNearTiles(7, 6, playerNum) || checkNearTiles(5, 2, playerNum) || checkNearTiles(4, 0, playerNum))
		{
			return playerNum;
		}
		break;
	default:
		//Invalid tile
		return 0;
	}
	
	return 0;
}

bool ATicTacToeTileGrid::checkNearTiles(int tile1, int tile2, int playerNum)
{
	bool won = (gridArray[tile1]->TileState == playerNum) && (gridArray[tile2]->TileState == playerNum);
	return won;
}