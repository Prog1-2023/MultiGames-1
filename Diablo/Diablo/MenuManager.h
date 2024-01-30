#pragma once
#include"IManager.h"
#include"Singleton.h"
#include"Menu.h"
#include<iostream>
#include<map>


using namespace std;

class MenuManager : public Singleton<MenuManager>, public IManager<string, Menu>
{
};



