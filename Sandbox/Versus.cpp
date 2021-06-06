#include "Versus.h"
#include "Grid.h"
#include "GameObject.h"

using namespace dae;

Versus::Versus()
	: dae::Scene{"Versus"}
{

	GameObject* levelGrid = new GameObject();
	levelGrid->AddComponent(new Grid{ 7, 20.f });
	levelGrid->SetPosition(860, 200);
	Add(levelGrid);
}

Versus::~Versus()
{
}

void Versus::Initialize()
{
}

void Versus::FixedUpdate()
{
}

void Versus::Update()
{
}

void Versus::LateUpdate()
{
}

void Versus::Render() const
{
}

void Versus::Unload()
{
}
