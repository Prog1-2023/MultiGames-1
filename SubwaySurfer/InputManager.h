#pragma once
#include "SFML/Graphics.hpp"
#include "Singleton.h"
#include <map>
#include <vector>
#include <functional>

using namespace std;
using namespace sf;

enum ActionType
{
    PRESSED, RELEASED
};

struct InputManagerData
{
    vector<Keyboard::Key> keys;
    function<void()> callback;
    ActionType actionType;
};

class InputManager : public Singleton<InputManager>
{
    vector<InputManagerData> keybinds;

public:
    InputManager();

private:
    function<void()> FindAction(const Keyboard::Key& _keyToFind, const ActionType& _aType);

public:
    void AddKeybind(const vector<Keyboard::Key>& _keys, const function<void()>& _callback, const ActionType& _aType);
    void ExecuteActions(const Event& _event);

};

