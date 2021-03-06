#pragma once

#include <stdio.h>
#include <iostream> // std::cout
#include <sstream> // stringstream
#include <memory> // smart pointers
#include <vector>

#define SAFE_DELETE(p) if (p) { delete (p); (p) = nullptr; }

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#pragma warning(push)
#pragma warning(disable : 26812)
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_opengl.h>
#include <SDL_mixer.h>
#pragma warning(pop)

#pragma warning(push)
#pragma warning(disable : 4189)
#pragma warning(disable : 26495)
#pragma warning(disable : 26812)
#include <imgui.h>
#include <imgui_internal.h>

#include "../3rdParty/imgui-1.81/backends/imgui_impl_sdl.h"
#include "../3rdParty/imgui-1.81/backends/imgui_impl_opengl2.h"
#pragma warning(pop)