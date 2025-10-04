#pragma once

class CLoadingScreen {
public:
	void Activate(bool relocating = false);
	void Deactivate();
};

CLoadingScreen* GetLoadingScreen();