#pragma once

#include <string>
#include <vector>


class GameConfigurations
{
public:
	int BackStepTime;
	int TurnTime;
	int TurnsInRound;
	int EndRoundEffect;
	bool NoMoveEffect;
	int MedicineHealthRestore;
	int MineExplosionDelay;
	int MinesCount;
	bool InvisibleMines;
	bool FallDamage;
	int WormHealth;
	int RoundsCount;
	bool Wind;
	int WaterLevel;

public:
	GameConfigurations();
};

