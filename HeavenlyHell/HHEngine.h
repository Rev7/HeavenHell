#pragma once

#include <SDL2\SDL.h>

class HHEngine
{
private:
	bool m_bRunning;

	SDL_Window*   m_pWindow;
	SDL_Renderer* m_pRenderer;

public:
	HHEngine(void);
	~HHEngine(void);

	bool init(const char* p_szTitle, int p_iXpos, int p_iYpos, int p_iWidth, int p_iHeight, bool p_bFullScreen);

	void render();
	void update() {}
	void handleEvents();
	void clean();

	// Accessors
	bool running() { return m_bRunning; }
};

