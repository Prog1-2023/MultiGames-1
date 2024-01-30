#include "Player.h"
#include "InputManager.h"

Player::Player(const string& _name, const Vector2f& _position, const Vector2f& _size) : Entity(_name, PLAYER, _position, _size, "")
{

	const vector<CollisionReaction>& _reactions = {
		CollisionReaction(WALL, [&](Shape* _shape) {}),
		CollisionReaction(HUNTER, [&](Shape* _shape) {}),
	};

	movement = new MovementComponent(0.25, DIRECTION_NONE, true, _reactions);
	collision = new CollisionComponent();

	SetOriginAtMiddle();
	InitKeybinds();
}

Player::~Player()
{
	delete movement;
	delete collision;
}

void Player::Loose()
{
}

void Player::Move()
{
	movement->TryToMove(collision, this,movement->GetDirectionData());
}

void Player::InitKeybinds()
{
	DirectionData& _movement = movement->GetDirectionData();
	InputManager* _inputManager = InputManager::GetInstance();
	_inputManager->AddKeybind({ Keyboard::Left, Keyboard::Q }, [&]() {_movement.SetDirection(DIRECTION_LEFT); }, PRESSED);
	_inputManager->AddKeybind({ Keyboard::Right, Keyboard::D }, [&]() {_movement.SetDirection(DIRECTION_RIGHT); }, PRESSED);
	_inputManager->AddKeybind({ Keyboard::Left, Keyboard::Q,Keyboard::Right, Keyboard::D }, [&]() {_movement.SetDirection(DIRECTION_NONE); }, RELEASED);
}

void Player::Update()
{
	Move();
}
