#pragma once

#include "Configurations.h"

class Singleton
{

protected:
	Singleton() : WindowClosed(false), config(Configurations()) {}

	static Singleton* singleton_;

public:

	Singleton(Singleton &other) = delete;

	void operator=(const Singleton &) = delete;

	static Singleton *GetInstance();

public:
	bool WindowClosed;
	Configurations config;
};

