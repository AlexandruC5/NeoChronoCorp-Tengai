#ifndef __MODULEULTI3_H__
#define __MODULEULTI3_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "ModuleParticles.h"
#include "SDL_mixer/include/SDL_mixer.h"

struct SDL_Texture;

class ModuleUlti3 : public Module
{
public:
	ModuleUlti3();
	~ModuleUlti3();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	Particle sword, sword_idle;
	SDL_Texture* graphics = nullptr;
	int posy = 20;

	Particle petal_1, petal_2, petal_3, petal_4, petal_5, petal_6;
	
	bool timer = false;
	int current_time = 0;
	int time_on_entry = 0;

	bool interval = false;
	int current_interval = 600;
	int interval_on_entry = 0;

	int num_petal = 0;
};

#endif // __MODULEULTI3_H__