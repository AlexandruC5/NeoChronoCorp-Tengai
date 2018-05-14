#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneAir.h"
#include "ModulePlayer3.h"
#include "ModulePartner3.h"
#include "ModuleUI.h"


#include "SDL\include\SDL_timer.h"

ModulePartner3::ModulePartner3()
{
	graphics = nullptr;
	current_animation = nullptr;

	/*spawn.PushBack
	spawn.PushBack
	spawn.PushBack
	spawn.PushBack
	spawn.speed

	iddle.PushBack
	iddle.PushBack
	iddle.PushBack
	iddle.PushBack
	iddle.speed

	charging.PushBack
	charging.PushBack
	charging.PushBack
	charging.speed

	decharging.PushBack
	decharging.PushBack
	decharging.PushBack
	decharging.PushBack
	decharging.speed

	charged.PushBack
	charged.PushBack
	charged.PushBack
	charged.PushBack
	charged.speed */

}

ModulePartner3::~ModulePartner3()
{
	//destroyer
}

bool ModulePartner3::Start()
{
	LOG("Loading partner textures");
	graphics = App->textures->Load("assets/sprite/Socrates_Spritesheet.png");
	if (graphics == nullptr)
	{
		LOG("Could not load partner textures")
			return false;
	}

	position.x = App->player3->position.x - 20;
	position.y = App->player3->position.y + 20;
	return true;
}

bool ModulePartner3::CleanUp()
{
	LOG("Unloading player");
	App->textures->Unload(graphics);
	graphics = nullptr;
	if (graphics != nullptr)
	{
		LOG("Could not unload partner textures")
			return false;
	}

	return true;
}


update_status ModulePartner3::Update()
{
	CheckState();

	PerformActions();

	if (App->input->keyboard[SDL_SCANCODE_K] == KEY_STATE::KEY_DOWN) {
		App->player3->power_up++;
	}
	if (App->input->keyboard[SDL_SCANCODE_L] == KEY_STATE::KEY_DOWN) {
		App->player3->power_up--;
	}

	//Draw partner
	SDL_Rect r = current_animation->GetCurrentFrame();

	//Set position
	position.x = App->player3->position.x - 20;
	position.y = App->player3->position.y - 20;

	return update_status::UPDATE_CONTINUE;
}


void ModulePartner3::CheckState()
{
	switch (state)
	{

	case NOT_EXISTING:
		if (App->player3->power_up == 1) 
		{
			exist = true;
			state = SPAWN;
		}
		break;

	case LEVEL_ONE:
		if (App->player3->power_up == 0) 
		{
			exist = false;
			state = NOT_EXISTING;
		}
		if (App->player3->power_up == 2) 
		{
			state = LEVEL_TWO;
		}
		//make it charge
		/*if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_REPEAT) {
			if (time_shoot) {
				time_on_entry = SDL_GetTicks();
				time_shoot = false;
			}
			current_time = SDL_GetTicks() - time_on_entry;
			if (current_time > 800) {
				time_shoot = true;
				state = LEVEL_ONE_CHARGE;
			}
		}
		if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_UP) {
			time_shoot = true;
		}*/
		break;

	case LEVEL_ONE_CHARGE:
		//make it shot fire while pressing a key
		/*if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_UP) {
			state = FIRE;
		}*/
		break;

	case LEVEL_TWO:
		if (App->player3->power_up <= 1)
		{
			state = LEVEL_ONE;
		}

		if (App->player3->power_up == 3)
		{
			state = LEVEL_THREE;
		}

		//make it charge
		/*if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_REPEAT) {
		if (time_shoot) {
		time_on_entry = SDL_GetTicks();
		time_shoot = false;
		}
		current_time = SDL_GetTicks() - time_on_entry;
		if (current_time > 800) {
		time_shoot = true;
		state = LEVEL_TWO_CHARGE;
		}
		}
		if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_UP) {
		time_shoot = true;
		}*/
		break;

	case LEVEL_TWO_CHARGE:
		//make it shot fire while pressing a key
		/*if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_UP) {
		state = FIRE;
		}*/
		break;

	case LEVEL_THREE:
		if (App->player3->power_up <= 2)
		{
			state = LEVEL_TWO;
		}

		if (App->player3->power_up == 4)
		{
			state = LEVEL_FOUR;
		}

		//make it charge
		/*if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_REPEAT) {
		if (time_shoot) {
		time_on_entry = SDL_GetTicks();
		time_shoot = false;
		}
		current_time = SDL_GetTicks() - time_on_entry;
		if (current_time > 800) {
		time_shoot = true;
		state = LEVEL_THREE_CHARGE;
		}
		}
		if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_UP) {
		time_shoot = true;
		}*/
		break;

	case LEVEL_THREE_CHARGE:
		//make it shot fire while pressing a key
		/*if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_UP) {
		state = FIRE;
		}*/
		break;

	case LEVEL_FOUR:
		if (App->player3->power_up <= 3)
		{
			state = LEVEL_THREE;
		}

		//make it charge
		/*if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_REPEAT) {
		if (time_shoot) {
		time_on_entry = SDL_GetTicks();
		time_shoot = false;
		}
		current_time = SDL_GetTicks() - time_on_entry;
		if (current_time > 800) {
		time_shoot = true;
		state = LEVEL_FOUR_CHARGE;
		}
		}
		if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_UP) {
		time_shoot = true;
		}*/
		break;

	case LEVEL_FOUR_CHARGE:
		//make it shot fire while pressing a key
		/*if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_UP) {
		state = FIRE;
		}*/
		break;

	case SPAWN:
		break;

	case FIRE:
		break;

	}
}


void ModulePartner3::PerformActions()
{

}