#pragma once
class Singleton
{

protected:
	Singleton() : lag(0)
	{

	}

	static Singleton* singleton_;

public:

	Singleton(Singleton &other) = delete;

	void operator=(const Singleton &) = delete;

	static Singleton *GetInstance();

public:
	long long lag;
};

