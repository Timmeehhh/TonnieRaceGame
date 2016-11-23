#ifndef CSTATEMANAGER_H
#define CSTATEMANAGER_H

#include <vector>
#include "SDL.h"
#include "CGameState.h"

using namespace std;

enum EGameState
{
	Start,
	Menu,
	Playing,
	Pause,
	Credits,
	Help,
	Scores
};

class CStateManager
{
public:
	void changeState(EGameState state, CEngine* engine);
	void pushState(CGameState* state);
	void popState();

	CGameState* getCurrentState();
private:
	vector<CGameState*> states;
};

#endif
