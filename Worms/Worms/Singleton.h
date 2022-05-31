#pragma once

#define UNICODE
#define sing Singleton::GetInstance() 

#include "Configurations.h"
#include "windows.h"
#include <tchar.h>

class Singleton
{

protected:
	Singleton() : 
		WindowClosed(false), 
		config(Configurations()),
		game_mouse_position_x(0), 
		game_mouse_position_y(0),
		isAnimation(false)
	{
		std::vector<wchar_t> pathBuf;
		DWORD copied = 0;
		do {
			pathBuf.resize(pathBuf.size() + MAX_PATH);
			copied = GetModuleFileName(0, &pathBuf.at(0), pathBuf.size());
		} while (copied >= pathBuf.size());

		pathBuf.resize(copied);

		std::wstring path(pathBuf.begin(), pathBuf.end());
		std::string res(path.begin(), path.end());
		
		int k = 0;

		while (res[res.size() - 1 - k] != '\\') k++; k++;
		while (res[res.size() - 1 - k] != '\\') k++;

		res = res.substr(0, res.size() - k);
		res += "Worms\\";

		GlobalPath = res;
	}

	static Singleton* singleton_;

public:

	Singleton(Singleton &other) = delete;

	void operator=(const Singleton &) = delete;

	static Singleton *GetInstance();

	static void ShowMap(GameMap* m, sf::RenderWindow *window);

public:
	bool WindowClosed;
	int game_mouse_position_x;
	int game_mouse_position_y;
	bool isAnimation;
	std::string GlobalPath;
	Configurations config;
};

