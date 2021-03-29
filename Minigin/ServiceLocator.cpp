#include "MiniginPCH.h"
#include "ServiceLocator.h"

Audio* ServiceLocator::audioService = nullptr;
NullAudio ServiceLocator::nullService = NullAudio{};