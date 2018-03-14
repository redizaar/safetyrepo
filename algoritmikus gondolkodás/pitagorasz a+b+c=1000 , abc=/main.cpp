#include <iostream>

using namespace std;

int main()
{
    int counter=0;
    int c=0;
    const int num=1000;
    for(int a=1;a<num/3;a++)
    {
        for(int b=2;b<num/2;b++)
        {
            c=num-a-b;
            if((((a*a)+(b*b))==(c*c)))
            {
                cout<<a<<" + "<<b<<" + "<<c<<endl;
                cout<<a*b*c<<endl;
                break;
            }
        }
    }
    return 0;
}
