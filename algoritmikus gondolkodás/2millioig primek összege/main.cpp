#include <iostream>

using namespace std;

int main()
{
    int num=2000000;
    long long int prim_sum=2;
    bool prim=true;
    for(int i=3;i<num;i++)
    {
        prim=true;
        for(int j=2;j<i-1;j++)
        {
            if(i%j==0)
            {
                prim=false;
                break;
            }
        }
        if(prim)
        {
            prim_sum+=i;
        }
        cout<<i<<endl;
    }
    cout<<prim_sum<<endl;
    return 0;
}
