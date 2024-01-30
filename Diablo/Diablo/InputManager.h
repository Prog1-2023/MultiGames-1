#include <SFML/Graphics.hpp>
#include <iostream>
#include<functional>
#include<map>

using namespace std;
using namespace sf;

class InputManager
{
    bool keyStates[Keyboard::KeyCount];
    map<int, function<void()>> keybinds;

public:
    InputManager();


public:
    // V�rifie si une touche est enfonc�e
    bool IsKeyPressed(Keyboard::Key _key) const
    {
        return keyStates[_key];
    }

    // M�thodes pour obtenir la direction du joueur
    bool IsMovingRight() const
    {
        return keyStates[Keyboard::D];

    }

    bool IsMovingLeft() const
    {
        return keyStates[Keyboard::Q];
    }

public:
    // Met � jour l'�tat des touches
    void Update(const Event& _event);
    void UpdateKey();
    void AddKeybinds(const int _param, const function<void()>& _lambda);



};



