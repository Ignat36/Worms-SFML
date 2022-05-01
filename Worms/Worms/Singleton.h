#pragma once
class Singleton
{

protected:
	Singleton() : WindowClosed(false)
	{

	}

	static Singleton* singleton_;

public:

	Singleton(Singleton &other) = delete;

	void operator=(const Singleton &) = delete;

	static Singleton *GetInstance();

public:
	bool WindowClosed;
};

