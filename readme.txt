Midestiny Engine

Was created for a school project on how to make and use a game engine.

The Midestiny Engine contains functionality such as:
- Entity Component System inspired by Unity
- Scenemanager that handles scenes inspired by Overlord
- SDL_mixer Audio service locator
- Command pattern used in both inputsystem and button system. Also tried to make the bullet work with it but there seems to be something wrong with it that I couldn't figure out.
- Logging using spdlog, inspired by The Cherno
- Text, Texture2D and SpriteSheets now fully working without any weird shenanigans.
- Observer pattern to keep track of lives
- METime to make elapsed seconds global. Also has the option of time manipulation.
- The waves of galaga are saved and read from binary files. There is even a static function in EnemyManager that serves as a way of creating said files.

Some Constraints
- GetComponent needs a very specific type of data. If you ask for the base class of a datatype you will receive the base class instead of the derived variant.
- You need to know how to deal with your sprites early on and require the amount of Sprites to be filled in.

Built in Visual Studio 2019 using C++17.


In the Sandbox I attempted to recreate a version of Galaga.

Author: Arno Poppe

Github: https://github.com/minoarno/MidestinyEngine
