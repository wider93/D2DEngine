#include "World.h"
#include "ECSCall.h"
#include "Square.h"
#include "Components.h"

World::World()
{
	_mainCamera = new Camera;

	EntityId square = CreateGameObject<Square>(Object_Layer::Player);
	Transform* tf = ComponentManager->AddComponent<Transform>(square, Vector3(200.0f, 100.0f, 0), Vector3(1.0f, 1.0f, 1.0f), Vector3(0, 0, 0));
	Sprite* sp = ComponentManager->AddComponent<Sprite>(square, L"Images\\TowerTest");
	tf->SetRectSize(sp->_spriteSize);
	BoxCollider* bc = ComponentManager->AddComponent<BoxCollider>(square, sp->_spriteSize);
	DetectComponent* dc = ComponentManager->AddComponent<DetectComponent>(square, 400.0f);
	AttackComponent* at = ComponentManager->AddComponent<AttackComponent>(square, 50, 0.5f);
	ECS::_ecs->SendEvent<RegistPlayer>(square);

	EntityId bg = CreateGameObject<Square>(Object_Layer::Background);
	Transform* tfbg = ComponentManager->AddComponent<Transform>(bg, Vector3(350.0f, 0, 0), Vector3(1.0f, 1.0f, 1.0f), Vector3(0, 0, 0));
	Sprite* spbg = ComponentManager->AddComponent<Sprite>(bg, L"Images\\TestBg");
	tfbg->SetRectSize(spbg->_spriteSize);
	BoxCollider* bcbg = ComponentManager->AddComponent<BoxCollider>(bg, spbg->_spriteSize);

}

World::~World()
{
	for (int i = 0; i < _objects.size(); i++) {
		EntityManager->DestroyEntity(_objects[i]);
	}
}

void World::PreUpdate(float dt)
{
}

void World::Update(float dt)
{

}

void World::PostUpdate(float dt)
{
}

void World::RegistEvent()
{
}

void World::UnRegistEvent()
{
}
