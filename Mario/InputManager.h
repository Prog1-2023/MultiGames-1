#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class InputManager 
{
public:
    virtual void ExecuteCallbacks(Event _event) = 0;
};