#include "game.h"

Game::Game()
{

}
void Game::beforeGame()
{
    readIn(chartxt);
    readIn(registered);
    int choice=0;
    while(choice!=4)
    {
        cout<<"-----------------------------------"<<endl;
        cout<<"Greetings Traveller"<<endl;
        cout<<"Welcome to Summer of Creating"<<endl;
        cout<<"What would you like to do ?"<<endl;
        cout<<"1. Log in"<<endl;
        cout<<"2. Register"<<endl;
        cout<<"3. Terms of use"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Type in your decision: "<<endl;
        cin>>choice;
        menu(choice);
        cout<<"-----------------------------------"<<endl;
    }
}
bool Game::menu(int &choice)
{
    switch(choice)
    {
        case 1:
        {
            bool correct=false;
            string username,password;
            cout<<"Please type in your Username : ";
            cin>>username;
            cout<<"Please type in your Passowrd : ";
            cin>>password;
            cout<<endl;
            auto it=users.begin();
            auto endit=users.end();
            for(;it!=endit;it++)
            {
                cout<<it->getUsername()<<" "<<it->getPassword()<<endl;
//                if(it->getUsername()==username && it->getPassword()==password)
//                {
//                    correct=true;
//                    gameStart(username);
//                }
            }
            if(correct==false)
                cout<<"Incorrect username or password";
            cout<<endl;
        }
        break;
        case 2:
        {
            string reg_name,reg_pw;
            bool correct=true;
            cout<<"Please type in your future Username: ";
            cin>>reg_name;
            auto it=users.begin();
            while(it!=users.end())
            {
                if(it->getUsername()==reg_name)
                    correct=false;
                it++;
            }
            if(correct==false)
                cout<<"An user is already using this name!"<<endl;
            else
            {
                cout<<"Please type in your future Password: ";
                cin>>reg_pw;
                writeOut(registered,reg_name,reg_pw);
                readIn(registered);
            }
        }
        break;
        case 3:
        {
            cout<<"Thank you for playing this game!"<<endl;
            cout<<"Hopefully you will have a great time!"<<endl;
            cout<<"If you find any bugs just let me know :D "<<endl;
            cout<<"Made by Tocki"<<endl;
            cout<<"Distibuted by Apple"<<endl;
            cout<<"Made in San Francisco USA,Silicon Valley"<<endl;
        }
        break;
        case 4:
            return false;
        break;
        default :
            cout<<"Give proper input please"<<endl;
        break;
    }
}
void Game::readIn(const string &fname)
{
    string in_name,in_pw;//registered
    string in_username,in_charname;//characters
    int in_ctype; // character type
    ifstream file(fname);
    if(file.is_open())
    {
        while (!file.eof())
        {
            if(fname=="registered.txt")
            {

                file>>in_name>>in_pw;
                if(in_name[0]!=' ')
                    users.push_back(User(in_name,in_pw));
            }
            else if(fname=="characters.txt")
            {
                file>>in_username>>in_charname>>in_ctype;
                if(in_username[0]!=' ')
                    characters.push_back(Character(in_username,in_charname,in_ctype));
            }
        }
        file.close();
    }
    else
        cout<<fname<<" file not found"<<endl;
}
void Game::writeOut(const string &fname, const string &str1, const string &str2)
{
    ofstream output(fname,std::ios::app);
    if(output.is_open())
    {
        output<<str1<<" "<<str2<<" ";
        output.close();
    }
    else
        cout<<fname<<" File not found"<<endl;
}
void Game::writeOut(const string &fname,const string &str1, const string &str2,int &c_type)
{
    ofstream output(fname,std::ios::app);
    if(output.is_open())
    {
        output<<str1<<" "<<str2<<" "<<c_type<<" ";
        output.close();
    }
    else
        cout<<fname<<" File not found"<<endl;
}

void Game::gameStart(const string &username)
{
    bool gaming=true;
    cout<<"Welcome to Azeroth "<<username<<endl;
    cout<<"Let's begin today's journey!"<<endl<<endl;
    while(gaming)
    {
        int choice=0;
        cout<<"1.Create a new character"<<endl;
        cout<<"2.Enter World"<<endl;
        cout<<"3.Exit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                characterCreation(username);
            break;
            case 2:
            {
                int i=1;
                list<string> karakterek;
                cout<<"Characters: "<<endl;
                karakterek=loadCharacters(username);
                auto it = karakterek.begin();
                for(;it!=karakterek.end();it++)
                {
                    cout<<i<<". "<<*it<<endl;
                    i++;
                }
                cout<<"Which character do you want to play with ?"<<endl;
                int which;
                cin>>which;
                string c_name;
                it=karakterek.begin();
                int j=1;
                for(;it!=karakterek.end();it++)
                {
                    if(j==which)
                        c_name=*it;
                    j++;
                }
                theGame(username,c_name);
            }
            break;
            case 3:
                gaming=false;
            break;
        }
    }
}

void Game::characterCreation(const string &username)
{
    cout<<"What kind of Character would you like to create?"<<endl;
    cout<<"--1.Warrior--"<<endl;
    cout<<"\tA melee champion , wears heavy armor , doesn't think twice about fighting."<<endl;
    cout<<"\tUses a dobule handedsword."<<endl;
    cout<<"\tUses rage as resource(spells) which generates after using spells or getting hit by an enemy."<<endl;
    cout<<"\tThe more rage the spell cost the more damage it will cause."<<endl;
    cout<<"\tMain stat : attack power."<<endl<<endl;
    cout<<"--2.Mage--"<<endl;
    cout<<"\tA ranged champion , wears light armor such as robes , can transfrom opponents to sheeps."<<endl;
    cout<<"\tUses a staff as a weapon."<<endl;
    cout<<"\tUses mana as resource(spells). Using both fire and frost spells."<<endl;
    cout<<"\tFrost spells will lower the damage of the next spell of his enemy."<<endl;
    cout<<"\tFire spells will inflict the enemy with a damage over time."<<endl;
    cout<<"\tMain stat: spell power , crit."<<endl<<endl;
    cout<<"--3.Tank--"<<endl;
    cout<<"\tA melee champiopn , wears very hevy armor , doesn't deals as much damage as others."<<endl;
    cout<<"\tUses a single handed sword and a shield."<<endl;
    cout<<"\tAlso doesn't takes as much damage as others , it thas a lot more chance to dodge attacks."<<endl;
    cout<<"\tUses rage as resource(spells) which generates after using spells or getting hit an enemy."<<endl;
    cout<<"\t Main stat : dodge , attack power."<<endl<<endl;
    cout<<"--4.Priest--"<<endl;
    cout<<"\tA ranged champion , wears light armor such as robes , can use light heals on itself."<<endl;
    cout<<"\tUses a staff as a weapon."<<endl;
    cout<<"\tUses mana as resource(spells). Using shadow magic as damage and holy magic as healing."<<endl;
    cout<<"\tShadow damage does a hard damage over time damage to the enemy."<<endl;
    cout<<"\tShadow damage also able to stack."<<endl;
    cout<<"\tMain stat : spell power , cirt."<<endl<<endl;
    cout<<"Choice:";
    int choice;
    cin>>choice;
    cout<<"Type in the mame of your champion: ";
    string c_name;
    bool exist=false;
    cin>>c_name;
    auto it=characters.begin();
    while(it!=characters.end()--)
    {
        if(it->getC_name()==c_name)
        {
            exist=true;
            it=characters.end();//ne fusson végig a ciklus, az első találat után álljon meg
        }
        if(it!=characters.end()) //mivel miután megtalálta egyenlővé teszem a végével , nem akarom még azután is léptetni egyet
            it++; // ->végtelen ciklus lenne
    }
    if(!exist)
    {
        int c_lvl=1,c_xp=0,c_hp,c_power=10;
        float c_crit=20,c_dodge=15;
        switch(choice)
        {
            case 1:
            {
                c_hp=150;
                c_dodge=20;
            }
            break;
            case 2:
            {
                c_hp=120;
                c_crit=35;
            }
            break;
            case 3:
            {
                c_hp=200;
                c_power=3;
                c_dodge=35;
            }
            break;
            case 4:
            {
                c_hp=120;
                c_crit=15;
            }
            break;
        }
        characters.push_front(Character(username,c_name,choice)); // push_backel az utolsó elemet beleteszi még1x WTFFFFFFF
        writeOut(chartxt,username,c_name,choice);
        //characterStatsOut(c_name,choice,c_lvl,c_xp,c_hp,c_power,c_crit,c_dodge);
    }
    else
        cout<<"Choose another charachter name, "<<c_name<<" character already exists"<<endl;
}

void Game::characterStatsOut(const string &c_name, int &c_type, int &c_lvl, int &c_xp, int &c_hp, int &c_power, int &c_crit, int &c_dodge)
{
    ofstream output("account.txt",std::ios::app);
    if(output.is_open())
    {
        output<<c_name<<" "<<c_type<<" "<<c_lvl<<" "<<c_xp<<" "<<c_hp<<" "<<c_power<<" "<<c_crit<<" "<<c_dodge<<" ";
        output.close();
    }
    else
        cout<<"Account File not found"<<endl;
}

void Game::characterStatsIn()
{
    string c_name;
    int c_type,c_lvl,c_xp,c_hp,c_power;
    float c_crit,c_dodge;
    ifstream file("account.txt");
    if(file.is_open())
    {
        while (!file.eof())
        {
            file>>c_name>>c_type>>c_lvl>>c_xp>>c_hp>>c_power>>c_crit>>c_dodge;
            if(c_name[0]!=' ')
                c_properties.push_back(Stats(c_name,c_type,c_lvl,c_xp,c_hp,c_power,c_crit,c_dodge));
        }
        file.close();
    }
    else
        cout<<" file not found"<<endl;
}
list<string> Game::loadCharacters(const string &username)
{
    list<string> clist;
    auto it=characters.begin();
    auto vege=characters.end();
    vege--;
    for(;it!=vege;it++)
    {
        if(it->getUsername()==username)
            clist.push_back(it->getC_name());
    }
    return clist;
}

void Game::theGame(const string &username, const string &c_name)
{
    characterStatsIn();
    list<Stats>::iterator index;
    string c_type;
    auto it=c_properties.begin();
    for(;it!=c_properties.end();it++)
    {
        if(it->getC_name()==c_name)
            index=it;
    }
    cout<<"\\\\\\\\\\\\\\\\\\\\\\"<<endl;
    cout<<"Progress this far : "<<endl;
    cout<<"Account : "<<username<<endl;
    cout<<"Character name : "<<c_name<<endl;
    cout<<"\\\\\\\\\\\\\\\\\\\\\\"<<endl;
    cout<<"Character statistics"<<endl;
    switch(index->getC_type())
    {
        case 1:
            c_type="Warrior";
        break;
        case 2:
            c_type="Mage";
        break;
        case 3:
            c_type="Tank";
        break;
        case 4:
            c_type="Priest";
        break;
    }
    cout<<"Class: "<<c_type<<endl;
    cout<<"Level: "<<index->getC_lvl()<<endl;
    cout<<"Xp points: "<<index->getC_xp()<<" out of "<<(index->getC_lvl()*75)<<endl;
    cout<<"Health points: "<<index->getC_hp()<<endl;
    cout<<"Champion power: "<<index->getC_power()<<endl;
    cout<<"Crit: "<<index->getC_crit()<<" %"<<endl;
    cout<<"Dodge: "<<index->getC_dodge()<<" %"<<endl;
    cout<<"//////////////////////"<<endl;
    cout<<"Shall we start?(Y / N)"<<endl;
    char answ;
    cin>>answ;
    switch(answ)
    {
        case 'Y':
        {
            map<string,int> megyek=Location::getInstance().locationLoad();
            string loc; // melyik megye
            auto itm=megyek.begin();
            for(;itm!=megyek.end();itm++)
            {
                if(index->getC_lvl()==itm->second || index->getC_lvl()-1==itm->second)
                    loc=itm->first; //location megtudása karakter szintje alapján  -- de a szint lehet pl 10 is
                                    //ilyenkor kettő között van Icecrown és Icecrown citadel
                                    //Mivel Icecrown citadel 11-estől van oda nem mehet -- tehát -1 a lvl amihez Icecrown tartozik
            }
            cout<<"Current Zone : "<<loc<<endl;

            srand(time(0));

            Mob bot;
            map<string,int> mobok=bot.mobLoad();
            string opponent;
            auto itmob=mobok.begin();
            for(;itmob!=mobok.end();itmob++)
            {
                if(itmob->second==index->getC_lvl() || itmob->second==index->getC_lvl()-1)
                {
                    opponent=itmob->first; //todo -- ne mindig ugyan az legyen az ellenség
                }
            }
            bot.setName(opponent);
            bot.setXp((index->getC_lvl()*75)/20);
            bot.setAttack((index->getC_power()*0.7));
            bot.setHp((index->getC_hp()*1.2));
            bot.setLvl(index->getC_lvl()+rand() % 2+1);
            cout<<"Your opponent : "<<endl;
            cout<<"Name: "<<opponent<<endl;
            cout<<"Level: "<<bot.getLvl()<<endl;
            cout<<"Health : "<<bot.getHp()<<endl;
            cout<<"Strenght : "<<bot.getAttack()<<endl;
            cout<<"Dodge: "<<bot.getDodge()<<endl;
            cout<<"Crit : "<<bot.getCirt()<<endl;
            string quote;
            int num=rand() % 6+1;
            cout<<num;
            switch(num)
            {
                case 1:
                    quote="You are not prepared!";
                break;
                case 2:
                    quote="Heh, this will be easy";
                break;
                case 3:
                    quote="You will lose this battle!";
                break;
                case 4:
                    quote="I already see you failing!";
                break;
                case 5:
                    quote="I won before this fight started";;
                break;
                case 6:
                    quote="I will defeat you in my sleep";
                break;
            }
            cout<<"Special quote : "<<quote<<endl;
            cout<<"If defeated " <<opponent<<" gives "<<(index->getC_lvl()*75)/2<<" experience points"<<endl;
            cout<<"Fight begins in: ";
            for(int i=1;i<4;i++)
            {
                cout<<i;
                cout<<endl;
                this_thread::sleep_for(chrono::seconds(2));
            }
            string str=index->getC_name();
            int type=index->getC_type();
            int lvl=index->getC_lvl();
            //Stats player(str,type,lvl);
           // combat(bot,player);
        }
        break;
        case 'N':
        break;
        default:
        break;
    }
}

bool Game::combat(Mob &m_obj, Stats &c_obj)
{
    switch(c_obj.getC_type())
    {
        case 1:
        break;
        case 2:
        break;
        case 3:
        break;
        case 4:
        break;
    }
}
