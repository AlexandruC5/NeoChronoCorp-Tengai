#include "Application.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include "Enemy_Turret.h"

Enemy_Turret::Enemy_Turret(int x, int y, int type) :Enemy(x, y,type)
{

	boss_sprite = App->textures->Load("assets/sprite/boss/Turret.png");

	spawn.PushBack({ 2,73,36,39 });
	spawn.PushBack({ 40,73,36,39 });
	spawn.PushBack({ 77,73,36,39 });
	spawn.speed = 0.20f;

	idle.PushBack({ 119,73,36,39 });
	idle.PushBack({ 153,73,36,39 });
	idle.PushBack({ 191,73,36,39 });
	idle.PushBack({ 229,73,36,39 });
	idle.PushBack({ 267,73,36,39 });
	idle.PushBack({ 305,73,36,39 });
	idle.speed = 0.20f;

	movement.PushBack({ 0,0 }, 30, &spawn);
	movement.PushBack({ 0,0 }, 900, &idle);

	this->type = type;

}


Enemy_Turret::~Enemy_Turret()
{
	App->textures->Unload(boss_sprite);
	
}

void Enemy_Turret::Move()
{

}

void Enemy_Turret::Draw(SDL_Texture* sprites)
{
	Enemy::Draw(boss_sprite);
}