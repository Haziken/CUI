#pragma once
#include <SDL.h>
#include "UIBase.h"
class Application
{
public:
	Application(UIBase* mainWindow);

	int show();
private:
	UIBase* base;
	SDL_Window* win;
	SDL_Renderer* ren;
};

