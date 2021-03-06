#include "SDL.h"
#include "CStateManager.h"
#include "CCamera.h"
#include "CCreditsState.h"
#include "CInputManager.h"
#include "CDebugLogger.h"

#include <SDL_syswm.h>
#include <vlc/vlc.h>

void CCreditsState::init(CEngine* engine)
{
	bool done = false;

	char const* vlc_argv[] =
	{
		//"--width=10",
		//"--height=400",
		"--fullscreen",
		//t.c_str(),
		"--no-embedded-video", "--no-video-deco",
	};
	int vlc_argc = sizeof(vlc_argv) / sizeof(*vlc_argv);
	CDebugLogger::PrintDebug("Init VLC");
	/* Load the VLC engine */
	inst = libvlc_new(vlc_argc, vlc_argv);

	// create a new item
	m = libvlc_media_new_path(inst, "Resources\\Videos\\outro.mp4");

	// create a media play playing environment
	mp = libvlc_media_player_new_from_media(m);
	//libvlc_media_player_set_hwnd(mp, engine->window);
	libvlc_video_set_format(mp, "RV16", 100, 100, 200);


	CDebugLogger::PrintDebug("Releasing media file");
	// no need to keep the media now
	libvlc_media_release(m);

	CDebugLogger::PrintDebug("Start playing video");
	// play the media_player
	libvlc_media_player_play(mp);


	//Wait 40 secs, length of the outro video
	Sleep(40000);

	CDebugLogger::PrintDebug("Stop playing video");
	// stop playing
	libvlc_media_player_stop(mp);

	CDebugLogger::PrintDebug("Releasing mediaplayer");
	// free the media_player
	libvlc_media_player_release(mp);

	CDebugLogger::PrintDebug("Release VLC");
	libvlc_release(inst);
}

void CCreditsState::clean(CEngine* engine)
{
}

void CCreditsState::pause()
{
}

void CCreditsState::resume()
{
}

void CCreditsState::handleEvents(CEngine* engine)
{
}

void CCreditsState::update(CEngine* engine)
{
	CDebugLogger::PrintDebug("Changing state to menu");
	engine->stateManager->changeState(Menu, engine);
}

void CCreditsState::draw(CEngine* engine)
{
}

void CCreditsState::input(CEngine* engine, SDL_Event* event)
{
	if (event->type == SDL_KEYDOWN)
	{
		switch (event->key.keysym.sym)
		{
		case SDLK_ESCAPE:

			engine->stateManager->changeState(Menu, engine);
			break;
		default:
			break;
		}
	}
	else if (event->type == SDL_MOUSEBUTTONDOWN)
	{
		int mouseX = event->motion.x;
		int mouseY = event->motion.y;
		switch (event->button.button)
		{
		case SDL_BUTTON_LEFT:
			if (mouseX > 35 && mouseX < 123 && mouseY > 650 && mouseY < 702)
			{
				engine->stateManager->changeState(Menu, engine);
			}

			break;
		default:
			break;
		}
	}
	else
	{
		engine->inputManager->Tick(event);
	}
}

CCreditsState::CCreditsState(CEngine* engine)
{
	init(engine);
}
