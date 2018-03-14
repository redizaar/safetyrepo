#include "location.h"
map<string, int> Location::locationLoad()
{
    megyek.insert(pair<string,int>("Durotar",1));
    megyek.insert(pair<string,int>("Barrens",3));
    megyek.insert(pair<string,int>("Thousand needles",5));
    megyek.insert(pair<string,int>("Un'Goro",7));
    megyek.insert(pair<string,int>("Icecrown",9));
    megyek.insert(pair<string,int>("Icecrown citadel",11));
    megyek.insert(pair<string,int>("Lich King",13));
    return megyek;
}
