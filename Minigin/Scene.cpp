#include "MiniginPCH.h"
#include "Scene.h"
#include "GameObject.h"

using namespace dae;

unsigned int Scene::m_IdCounter = 0;

Scene::Scene(const std::string& name)
	: m_Name{ name }
{
}

Scene::~Scene()
{
	for (int i = 0; i < int(m_Objects.size()); i++)
	{
		delete m_Objects[i];
		m_Objects[i] = nullptr;
	}
}

void Scene::Initialize()
{
	for (GameObject* object : m_Objects)
	{
		object->Initialize();
	}
}

void Scene::Unload()
{
	
}


void Scene::Add(GameObject* object)
{
	m_Objects.push_back(object);
}

void Scene::FixedUpdate()
{
	for(GameObject* object : m_Objects)
	{
		object->FixedUpdate();
	}
}

void Scene::Update()
{
	for(GameObject* object : m_Objects)
	{
		object->Update();
	}
}

void Scene::LateUpdate()
{
	for (GameObject* object : m_Objects)
	{
		object->LateUpdate();
	}
}

void Scene::Render() const
{
	for (const GameObject* object : m_Objects)
	{
		object->Render();
	}
}