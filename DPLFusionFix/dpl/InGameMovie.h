#pragma once

class CInGameMovie {
public:
	void PlayMovie(char* szFileName, bool bLoop = false, bool pauseAtEnd = false);
};

CInGameMovie* GetInGameMovie();