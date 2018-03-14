#include "warrior.h"

Warrior::Warrior(const string c_name,int type):Character(c_name,type)
{
}

int Warrior::b_attack(int power,int crit)
{
    srand(time(0));
    int num=rand() % 100 +1;
    if(crit>num)
    {
        cout<<"Critical strike!"<<endl;
        return power*2;
    }
    return power;
}
