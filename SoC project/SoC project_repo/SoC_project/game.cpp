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
            endit--;//a szóköz miatt ne írja ki kétszer az utolsót
            for(;it!=endit;it++)
            {
                if(it->getUsername()==username && it->getPassword()==password)
                {
                    correct=true;
                    gameStart(username);
                }
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
            exit(0);
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
                users.push_back(User(in_name,in_pw));
            }
            else if(fname=="characters.txt")
            {
                file>>in_username>>in_charname>>in_ctype;
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
        characterStatsOut(c_name,choice,c_lvl,c_xp,c_hp,c_power,c_crit,c_dodge);
    }
    else
        cout<<"Choose another character name, "<<c_name<<" character already exists"<<endl;
}

void Game::characterStatsOut(const string c_name, int c_type, int c_lvl, int c_xp, int c_hp, int c_power, int c_crit, int c_dodge)
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
            c_type="Priest";
        break;
        case 4:
            c_type="Tank";
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
            auto itmob=mobok.begin();
            string opponent;
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
            bot.setLvl(index->getC_lvl()+rand() % 1+0);
            cout<<"Your opponent : "<<endl;
            cout<<"Name: "<<bot.getName()<<endl;
            cout<<"Level: "<<bot.getLvl()<<endl;
            cout<<"Health : "<<bot.getHp()<<endl;
            cout<<"Strenght : "<<bot.getAttack()<<endl;
            cout<<"Dodge: "<<bot.getDodge()<<endl;
            cout<<"Crit : "<<bot.getCirt()<<endl;
            string quote;
            int num=rand() % 6+1;
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
            cout<<"If defeated " <<bot.getName()<<" gives "<<(index->getC_lvl()*75)/2<<" experience points."<<endl;
            cout<<"Fight begins in: ";
            for(int i=3;i>0;i--)
            {
                cout<<i<<"..";
                this_thread::sleep_for(chrono::seconds(2));
            }
            cout<<endl;
            //string c_name=index->getC_name();
            //int c_type=index->getC_type(),c_lvl=index->getC_lvl(),c_xp=index->getC_xp(),c_hp=index->getC_hp(),c_power=index->getC_power();
            //float c_crit=index->getC_crit(),c_dodge=index->getC_dodge();
            //Stats player(c_name,c_type,c_lvl,c_xp,c_hp,c_power,c_crit,c_dodge); //WTFFFFFFFFFFFFFFFFFFFFFFFFFF csak így jó valamiért  -- át kell írni constra az inteket konsturktorba WTF  &-volt a baja
            //no known conversion to int to &int

            //ideiglenes objektum miatt nem volt jó , a const kitolja az ideiglenes objektum élettartamát
            //igy már nem a full expression végéig fog tartani hanem a függvény végéig
            //solution
            Stats player(index->getC_name(),index->getC_type(),index->getC_lvl(),index->getC_xp(),index->getC_hp(),index->getC_power(),index->getC_crit(),index->getC_dodge());
//            combat(bot,player);
            //Character player(index->getC_name(),index->getC_type());
            combat(bot,player);
        }
        break;
        case 'N':
        break;
        default:
        break;
    }
}

bool Game::combat(Mob m_obj, Stats c_obj)
{
    max_hp=c_obj.getC_hp();
    srand(time(0));
    int num=rand() % 100 +1;
    int sebzes=0;
    int rage=0;//warrior
    bool isPriest=false;//dot miatt más a sebzes kiirás
    int mana=100;

    const int e_full_hp=m_obj.getHp();
    while(m_obj.getHp()>=0 && c_obj.getC_hp()>=0)
    {
        switch(c_obj.getC_type())
        {
            case 1:
            {
                auto b_attack=[=](int attack,float crit)
                { if(crit>num)
                        return attack*2;
                    return attack;
                };
                cout<<"---------------------------------"<<endl;
                cout<<"Enemy hp: "<<m_obj.getHp()<<endl;
                cout<<"Current rage : "<<rage<<endl;
                cout<<"---------------------------------"<<endl;
                cout<<"1. Basic attack "<<endl;//doesn't cost rage , low dmg
                cout<<"2. Charge "<<endl;//doesn't cost rage , very low dmg , generares rage instead
                if(rage>=30)
                {
                    cout<<"3. Heavy attack (cost atleast 30 rage)" <<endl;
                    cout<<"\t the more rage you have the higher dmg it will cause"<<endl;
                }
                if((rage>=30) && ((m_obj.getHp()/e_full_hp)<=0.3))
                {
                    cout<<"4. Execute (cost atleast 30 range)"<<endl;
                        cout<<"\t kill strike your enemy is below 30%"<<endl;
                }
                if(rage>=15)
                {
                    cout<<"5. Shield wall"<<endl;
                    cout<<"\tnext damage taken is reduced by 60%"<<endl;//todo

                }
                cout<<"Choice: "<<endl;
                int choice;
                cin>>choice;
                switch(choice)
                {
                    case 1:
                    {
                        sebzes=b_attack(c_obj.getC_power(),c_obj.getC_crit());
                        if(sebzes>c_obj.getC_power())
                            rage+=30;//ha cirtel több raget kap
                        rage+=15; //különben csak 15öt
                    }
                    break;
                    case 2:
                    {
                        sebzes=b_attack((c_obj.getC_power()/2),c_obj.getC_crit()); //charge fele sebzés
                        if(sebzes>(c_obj.getC_power()/2))
                            rage+=40; //viszont több raget ad
                        rage+=25;
                    }
                    break;
                    case 3:
                    {
                        if(rage>=30)
                        {
                            auto h_attack=[=](int power,int crit,int rage)
                            {
                                if(crit>num)return (power*2)+rage;// power*2 = critelt    (rage/2)*2==rage critelt tehát a rages dmg is dupla
                                    return power+(rage/2);
                            };
                            rage-=30;
                            sebzes=h_attack(c_obj.getC_power(),c_obj.getC_crit(),rage);
                        }
                    }
                    break;
                    case 4:
                        sebzes=b_attack(c_obj.getC_power()*3,c_obj.getC_crit()*0.5)+(rage/2);//execute 3x attackpower + dupla esély critre + rage dmg
                    break;
                    case 5:
                    //todo
                    break;
                }
                if(playerBlinded)
                {
                    cout<<"You are Silenced for this round!"<<endl;
                    playerBlinded=false;
                }
                else
                    player_damage(isPriest,sebzes,m_obj);
                mobs_damage(m_obj,c_obj);
            }
            break;
            case 2:
            {
                static int no_crits=0;//critek száma
                static int combu=0;//ha nagyobb mint 1 fix crit
                static bool immune=false;
                c_obj.setC_crit(40);
                cout<<"---------------------------------"<<endl;
                cout<<"Enemy hp: "<<m_obj.getHp()<<endl;
                cout<<"Current mana : "<<mana<<endl;
                if(combu>=1)
                    cout<<"Combustion is active for "<<combu<<" more spells"<<endl;
                cout<<"---------------------------------"<<endl;
                cout<<"1. Fireball "<<endl;//low dmg low mana cost 2 crit=pyro 3x damage
                cout<<"2. Fireblast "<<endl;//low dmg fix crit
                cout<<"3. Pyroblast "<<endl;//damage depens on how many have you critted
                cout<<"4. Combustion "<<endl;//gives you 2 crit
                cout<<"5. Iceblcok "<<endl;//immune for 1 attack
                cout<<"Choice: "<<endl;
                int choice;
                cin>>choice;
                switch(choice)
                {
                    case 1:
                    {
                        cout<<"Casting fireball "<<endl;
                        cout<<"----";
                        this_thread::sleep_for(chrono::milliseconds(800));
                        cout<<"----";
                        cout<<endl;
                        this_thread::sleep_for(chrono::milliseconds(800));
                        auto fireball=[=](int power,int crit)
                        {
                            if((crit>num) || (combu>=1))
                            {
                                return power*2;
                            }
                            return power;
                        };
                        sebzes=fireball(c_obj.getC_power(),c_obj.getC_crit());
                        if((sebzes==c_obj.getC_power()*2) && (combu>=1))
                        {
                            combu--;
                            no_crits++;
                        }
                        else if((sebzes==c_obj.getC_power()*2) && (combu==0))
                            no_crits++;
                    }
                    break;
                    case 2:
                    {
                        sebzes=c_obj.getC_power();
                        no_crits++;
                    }
                    break;
                    case 3:
                    {
                        auto pyroblast=[=](int power,int crit){
                            if(no_crits>=2)
                            {
                                return power*4;
                            }
                            else if(((no_crits<=2) && (num>crit)) || (combu>=1))//combustion aktív
                            {
                                return power*2;
                            }
                            return power;
                        };
                        sebzes=pyroblast(c_obj.getC_power(),c_obj.getC_crit());
                        if(sebzes==c_obj.getC_power()*4)//ha 2 crites pyrot haszált
                            no_crits=0;                 //critek száma reset -- ne tudja örökké nyomni
                        else if((sebzes==c_obj.getC_power()*2) && (combu>=1))//critelt combu miatt
                        {
                            combu--;
                            no_crits++;
                        }
                        else if((sebzes==c_obj.getC_power()*2) && (combu==1))//simán critelt
                            no_crits++;
                    }
                    break;
                    case 4:
                    {
                        cout<<"Now your next 2 spells are going to be a critical strirke"<<endl;
                        cout<<"Fireblast doesn't count because it always crits!"<<endl;
                        combu+=2;
                    }
                    break;
                    case 5:
                    {
                        cout<<"You became immune for the next round"<<endl;
                        immune=true;//todo
                    }
                    break;
                }
                if(playerBlinded)
                {
                    cout<<"You are Silenced for this round!"<<endl;
                    playerBlinded=false;
                }
                else
                    player_damage(isPriest,sebzes,m_obj);
                mobs_damage(m_obj,c_obj);
            }
            break;
            case 3:
            {
                isPriest=true;
                static bool voidform=false;
                int dot_vp;
                int dot_swd;
                static int no_vpdot;
                static int no_swddot;
                static int sanity;//if sanity is zero voidform is cancelled , each spell cost 10 sanity , starts from 50
                cout<<"---------------------------------"<<endl;
                cout<<"Enemy hp: "<<m_obj.getHp()<<endl;
                if(!voidform) cout<<"Current mana : "<<mana<<endl;
                else cout<<"Void form is active for "<<(sanity/10)<<" more spells"<<endl; //while voidform is active spells cause 30%more damage
                cout<<"---------------------------------"<<endl;
                cout<<"1. Vampiric touch "<<endl;
                cout<<"2. Shadow word : Death "<<endl;
                cout<<"3. Mindblast "<<endl;
                if(!voidform) cout<<"4. Voidform "<<endl;
                else cout<<"4.Void Bolt"<<endl;
                cout<<"5. Dispersion "<<endl; //90% damage reduction next round
                cout<<"Choice: "<<endl;
                int choice;
                cin>>choice;
                switch(choice)
                {
                    case 1:
                    {
                        auto vp=[=](int power,int crit)
                        {
                            if(crit>num) return power*1.75;
                            else return power*0.8;
                        };
                        if(!voidform)
                        {
                            sebzes=vp(c_obj.getC_power(),c_obj.getC_crit());
                        }
                        else
                        {
                            sebzes=vp(c_obj.getC_power()*1.2,c_obj.getC_crit());//void form active = 20% more damage
                            sanity-=10;
                        }
                        cout<<"Vampiric dot applied to the target for 2 rounds"<<endl;
                        no_vpdot+=2;//Vampiric touch does Damage Over Time for 2 rounds , it can stack
                    }
                    break;
                    case 2:
                    {
                        auto swd=[=](int power,int crit)
                        {
                            if(crit>num) return power*1.45;
                            else return power*0.65;
                        };
                        if(!voidform)
                        {
                            sebzes=swd(c_obj.getC_power(),c_obj.getC_crit());
                            cout<<"voidform off"<<endl;
                        }
                        else
                        {
                            sebzes=sebzes=swd(c_obj.getC_power()*1.2,c_obj.getC_crit());
                            sanity-=10;
                        }
                        cout<<"Shadow word : Death dot applied to the target for 2 rounds"<<endl;
                        no_vpdot+=2;
                    }
                    break;
                    case 3:
                    {
                        auto mindblast=[=](int power,int crit)
                        {
                            if(crit>num) return power*1.45;
                            else return power*0.65;
                        };
                        if(!voidform)
                            sebzes=mindblast(c_obj.getC_power(),c_obj.getC_crit());
                        else
                        {
                            sebzes=mindblast(c_obj.getC_power()*1.3,c_obj.getC_crit());
                            sanity-=10;
                        }
                    }
                    break;
                    case 4:
                    {
                        if(!voidform)
                        {
                            cout<<"Stepping into the void "<<endl;
                            this_thread::sleep_for(chrono::seconds(1));
                            cout<<"Ug ahsal ak'ner tok...."<<endl;
                            this_thread::sleep_for(chrono::seconds(1));
                            voidform=true;
                            sanity=50;
                        }
                        else
                        {
                            if(c_obj.getC_crit()>num)
                                sebzes=c_obj.getC_power()*2.3;
                            else
                                sebzes=c_obj.getC_power()*1.3;
                            sanity-=10;
                        }
                    }
                    break;
                    case 5:
                    break;
                }
                if(no_vpdot>=1)
                {
                    no_vpdot--;
                    dot_vp=c_obj.getC_power()*0.3;//the damage overtime is 30% of the normal power for vampiric touch
                }
                else dot_vp=0;
                if(no_swddot>=1)
                {
                    no_swddot--;
                    dot_swd=c_obj.getC_power()*0.3;
                }
                else dot_swd=0;
                isPriest=true;
                if(sanity==0)
                    voidform=false;
                if(playerBlinded)
                {
                    cout<<"You are Silenced for this round!"<<endl;
                    playerBlinded=false;
                }
                else
                    player_damage(isPriest,sebzes,m_obj,dot_vp,dot_swd);
                mobs_damage(m_obj,c_obj);
            }
            break;
            case 4:
            {
            }
            break;
        }
    }
}
void Game::player_damage(bool isPriest,int sebzes,Mob &m_obj,int dot_vp,int dot_swd)
{
    if(!isPriest)
    {
        cout<<"You dealt "<<sebzes<<" damage to you opponent"<<endl;
        m_obj.setHp(m_obj.getHp()-sebzes);
        cout<<"Your enemy's hp: "<<m_obj.getHp()<<endl;
    }
    else
    {
        cout<<"You dealt "<<sebzes<<" damage to you opponent directy "<<endl;
        if(dot_vp!=0 || dot_swd!=0)
            cout<<"You dealt "<<(dot_vp+dot_swd)<<" by DOTs"<<endl;
        m_obj.setHp((m_obj.getHp()-(sebzes+dot_vp+dot_swd)));
        cout<<"Your enemy's hp: "<<m_obj.getHp()<<endl;
    }
    cout<<"##Opponent's turn!"<<endl;
    cout<<endl;
}
void Game::mobs_damage(Mob &m_obj, Stats &c_obj)
{
    static int darkness=0;
    srand(time(0));
    int spell=rand()% 3+1;
    if(darkness>=40)
    {
        switch(spell)
        {
            case 1:
                cout<<gotAttacked(spell,overForty)<<" by "<<m_obj.getName()<<endl;
                darkness-=40;
            break;
            case 2:
                cout<<gotAttacked(spell,overForty)<<" by "<<m_obj.getName()<<endl;
                darkness-=35;
            break;
            case 3:
                cout<<gotAttacked(spell,overForty)<<" by "<<m_obj.getName()<<endl;
                darkness-=40;
            break;
        }
    }
    else
    {
        switch(spell)
        {
            case 1:
            {
                cout<<gotAttacked(spell,overForty)<<" by "<<m_obj.getName()<<endl;
                darkness+=10;
            }
            break;
            case 2:
            {
                cout<<gotAttacked(spell,overForty)<<" by "<<m_obj.getName()<<endl;
                darkness+=15;
            }
            break;
            case 3:
            {
                cout<<gotAttacked(spell,overForty)<<" by"<<m_obj.getName()<<endl;
                darkness+=8;
            }
            break;
        }
    }
    int sufferedDmg=damageDealt(spell,m_obj,overForty);

    //ha 0val tér vissza a damageDealt akkor az azt jelenti hogy blindolta a playert 1 körre
    if(sufferedDmg!=0)
        cout<<"You suffered "<<sufferedDmg<<" damage this round"<<endl;
    else
        playerBlinded=true;
    c_obj.setC_hp(c_obj.getC_hp()-sufferedDmg);
    if(darkness>=40)
        overForty=true;
    else
        overForty=false;
    if((c_obj.getC_hp()/max_hp)<=0.2)
    {
        cout<<"---------------------------------"<<endl;
        cout<<"You are below 20%!!"<<endl;
        cout<<"You have: "<<c_obj.getC_hp()<<" health points"<<endl;
        cout<<"Percentage: "<<(c_obj.getC_hp()/max_hp)*100<<endl;
        cout<<"---------------------------------"<<endl;
    }
    else
    {
        cout<<"---------------------------------"<<endl;
        cout<<"You have: "<<c_obj.getC_hp()<<" health points"<<endl;
        cout<<"Percentage: "<<(c_obj.getC_hp()/max_hp)*100<<endl;
        cout<<"---------------------------------"<<endl;
    }
}

string Game::gotAttacked(int random, bool overForty)
{
    if(!overForty)
    {
        switch(random)
        {
            case 1:
                return "Basic attack was Performed on you";
            break;
            case 2:
                return "You got hit by spell Source of Darkness";
            break;
            case 3:
                return "You got Stabbed in the back";
            break;
        }
    }
    else //Enemy's darkness is over 40 , heavier attack
    {
        switch(random)
        {
            case 1:
                return "You got Blinded for one round!";
            break;
            case 2:
                return "Darkness... You got paranoid!";
            break;
            case 3:
                return "Execute attack was performed on you! ";
            break;
        }
    }
}

int Game::damageDealt(int whichSpell, Mob obj, bool overForty)
{
    //kevesebb mint 40 darknesse van
    if(!overForty)
    {
        switch(whichSpell)
        {
            case 1:
                return obj.getAttack();
            break;
            case 2:
                return obj.getAttack()*0.7;//-30% mert több darknesst generál
            break;
            case 3:
                return obj.getAttack()*1.15;//+15% mert kevesebb darknesst generál
            break;
        }
    }
    else//több vagy 40 darknesse van
    {
        switch(whichSpell)
        {
            case 1:
                return 0;//blind
            break;
            case 2:
                return obj.getAttack()*1.5;
            break;
            case 3:
                return obj.getAttack()*1.85;
            break;
        }
    }
}
