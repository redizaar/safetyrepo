#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <fstream>
#include <list>
#include "user.h"
#include "character.h"
#include "warrior.h"
#include "mage.h"
#include "priest.h"
#include "tank.h"
#include "stats.h"
#include "location.h"
#include "mob.h"
#include "thread"
#include "time.h"
using namespace std;
class Game
{
    list<User> users;
    list<Character> characters;
    list<Stats> c_properties;
    string registered="registered.txt";
    string chartxt="characters.txt";
public:
    Game();
    void beforeGame();
    bool menu(int &choice);
    void readIn(const string &fname);
    void writeOut(const string &fname, const string &str1, const string &str2, int &c_type);
    void writeOut(const string &fname, const string &str1, const string &str2);
    void gameStart(const string &username);
    void characterCreation(const string &username);
    void characterStatsOut(const string &c_name,int &c_type,int &c_lvl,int &c_xp,int &c_hp,int &c_power,int &c_crit,int &c_dodge);
    void characterStatsIn();
    list<string> loadCharacters(const string &username);
    void theGame(const string &username,const string &c_name);
    bool combat(Mob &m_obj, Stats &c_obj);
};

#endif // GAME_H
