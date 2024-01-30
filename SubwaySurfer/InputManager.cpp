#include "InputManager.h"

void InputManager::AddKeybind(const vector<Keyboard::Key>& _keys, const function<void()>& _callback, const ActionType& _aType)
{
    keybinds.push_back({ _keys, _callback, _aType });
}

InputManager::InputManager()
{
    keybinds = vector<InputManagerData>();
}

function<void()> InputManager::FindAction(const Keyboard::Key& _keyToFind, const ActionType& _aType)
{
    for (const InputManagerData& _data : keybinds)
    {
        bool _contains = find(_data.keys.begin(), _data.keys.end(), _keyToFind) != _data.keys.end();
        if (_contains && _data.actionType == _aType)
        {
            return _data.callback;
        }
    }

    return function<void()>();
}

void InputManager::ExecuteActions(const Event& _event)
{
    if (_event.type == _event.KeyPressed || _event.type == _event.KeyReleased)
    {
        ActionType _type = _event.type == _event.KeyPressed ? PRESSED : RELEASED;
        function<void()> _callback = FindAction(_event.key.code, _type);
        if (_callback)
        {
            _callback();
        }
    }
}
