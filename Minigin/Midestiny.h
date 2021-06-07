#pragma once
#define HAVE_M_PI

//For use outside of the engine only

#include "Application.h"

//-- Entry Point---------------------
#include "EntryPoint.h"
//-----------------------------------

#include "SceneManager.h"
#include "Scene.h"
#include "GameObject.h"

#include "BaseComponent.h"
#include "FPSComponent.h"
#include "TextComponent.h"
#include "InputManager.h"
#include "Commands.h"
#include "Transform.h"
#include "Texture2D.h"

#include "EventObserver.h"
#include "EventSubject.h"

#include "ResourceManager.h"

#include "ServiceLocator.h"

using namespace dae;