#include "SDL.h"
#include "CStateManager.h"
#include "CIntroState.h"
#include "CPlayState.h"
#include "CLoadingState.h"
#include "CHelpState.h"
#include "CScoresState.h"
#include "CCreditsState.h"
#include "CLevelSelectorState.h"
#include "CProfileCreationState.h"
#include "CPauseState.h"

CStateManager::CStateManager(CEngine* engine)
{
	this->playState = nullptr;
	this->engine = engine;
}

CStateManager::~CStateManager()
{
	getCurrentState()->clean(engine);

	if (playState != nullptr) {
		playState->clean(engine);
		playState = nullptr;
	}

	for (CGameState* state : states)
	{
		if (state != nullptr) {
			delete state;
		}
		state = nullptr;
	}

	states.clear();
}

void CStateManager::changeState(EGameState state, CEngine* engine, bool clean)
{
	if (states.size() > 0 && clean)
	{
		getCurrentState()->clean(engine);
	}

	switch (state)
	{
	case Start: states.push_back(new CIntroState(engine));
		break;
	case Menu: states.push_back(new CIntroState(engine));
		break;
	case Playing: states.push_back(new CPlayState(engine));
		break;
	case Pause: states.push_back(new CPauseState(engine));
		break;
	case Resumed: states.push_back(this->playState);
		states.erase(states.begin()+(states.size()-3));
		playState = nullptr;
		break;
	case Credits: states.push_back(new CCreditsState(engine));
		break;
	case Help: states.push_back(new CHelpState(engine));
		break;
	case Loading: states.push_back(new CLoadingState(engine));
		break;
	case Scores: states.push_back(new CScoresState(engine));
		break;
	case LevelSelector: states.push_back(new CLevelSelectorState(engine));
		break;
	case ProfileCreation: states.push_back(new CProfileCreationState(engine));
		break;
	}
	return;
}

void CStateManager::pushState(CGameState* state)
{
	states.push_back(state);
	return;
}

void CStateManager::popState()
{
	states.pop_back();
	return;
}

void CStateManager::changeStateToPause(CEngine * engine, CPlayState* playState)
{
	this->playState = playState;
	changeState(Pause, engine, false);
	std::cout << "troep is naar pause";
}

CGameState* CStateManager::getCurrentState()
{
	CGameState* currentState = states.back();
	return currentState;
}
