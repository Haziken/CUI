#include "Application.h"

Application::Application(UIBase* mainWindow)
	: base(mainWindow)
{
	iv4 size = base->getFormat().size;
	win = SDL_CreateWindow(base->getTitle().c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, size.w, size.h, SDL_WINDOW_SHOWN);
	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawBlendMode(ren, SDL_BLENDMODE_BLEND);
}

int Application::show()
{
	SDL_Event e;
	bool run = true;
	while (run)
	{
		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
			case SDL_QUIT:
				run = false;
			}
		}
		base->Update(&e);
		base->Draw(ren);
		SDL_RenderPresent(ren);
	}
	return 0;
}
