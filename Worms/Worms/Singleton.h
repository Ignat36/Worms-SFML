#pragma once

#include "Configurations.h"

class Singleton
{

protected:
	Singleton() : 
		WindowClosed(false), 
		config(Configurations()),
		game_mouse_position_x(0), 
		game_mouse_position_y(0),
		isAnimation(false)
	{}

	static Singleton* singleton_;

public:

	Singleton(Singleton &other) = delete;

	void operator=(const Singleton &) = delete;

	static Singleton *GetInstance();

public:
	bool WindowClosed;
	int game_mouse_position_x;
	int game_mouse_position_y;
	bool isAnimation;
	Configurations config;
};

