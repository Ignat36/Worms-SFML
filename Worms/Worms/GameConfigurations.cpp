#include "GameConfigurations.h"

GameConfigurations::GameConfigurations()
{
	BackStepTime = 5 * 1e6;
	TurnTime = 30 * 1e6;
	TurnsInRound = 16;
	EndRoundEffect = 0;
	NoMoveEffect = false;
	MedicineHealthRestore = 100;
	MineExplosionDelay = 3;
	MinesCount = 6;
	InvisibleMines = false;
	FallDamage = true;
	WormHealth = 200;
	RoundsCount = 1;
	Wind = false;
	WaterLevel = 1990;
}
