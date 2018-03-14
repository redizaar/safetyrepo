#include <iostream>

using namespace std;

int main()
{
    int prim_counter=1;
    bool counting=true;
    bool not_prim;
    int num=3;
    int i;
    while(counting)
    {
        not_prim=false;
        for(i=2;i<num;i++)
        {
            if(num%i==0)
            {
                not_prim=true;
                break;
            }
        }
        if(!not_prim)
        {
            prim_counter++;
            if(prim_counter==10001)
            {
                counting=false;
                cout<<num<<endl;
            }
        }
        num++;
    }
    return 0;
}
