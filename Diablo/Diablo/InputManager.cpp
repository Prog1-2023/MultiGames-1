#include "InputManager.h"

InputManager::InputManager()
{
    // Initialise les états des touches
    for (int _index = 0; _index < Keyboard::KeyCount; _index++)
    {
        keyStates[_index] = false;
    }
}

void InputManager::Update(const Event& _event)
{
    if (_event.type == Event::KeyPressed || _event.type == Event::KeyReleased)
    {
        keyStates[_event.key.code] = _event.type == Event::KeyPressed;
    }
}

void InputManager::UpdateKey()
{
    for (const auto& _pair : keybinds)
    {
        if (keyStates[_pair.first])
        {
            function<void()> _callbacks = _pair.second;
            if (!_callbacks)return;
            _callbacks();
        }
    }
}

void InputManager::AddKeybinds(const int _param, const function<void()>& _lambda)
{
    keybinds[_param] = _lambda;
}



