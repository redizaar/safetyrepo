#include <iostream>

using namespace std;

int main()
{
    string szam;
    string palindrome;
    int bingo=0;
    int num;
    for(int i=1000;i>99;i--)
    {
        szam=to_string(i);
        palindrome=to_string(i)+szam[2]+szam[1]+szam[0];
        num=stoi(palindrome);
        for(int j=1000;j>99;j--)
        {
            if(bingo==0)
            {
                for(int n=1000;n>99;n--)
                {
                    if((j*n)==num)
                    {
                        cout<<"palindrome: "<<num<<" ("<<i<<" * "<<j<<") "<<endl;
                        bingo++;
                        break;
                    }
                }
            }
        }
   }
//    double num;
//    int jegyek=0;
//    cin>>num;

//    int ref=num;
//    while(num>1)
//    {
//        num/=10;
//        jegyek++;
//    }
//    double new_num=num;
//    for(int i=0;i<jegyek;i++)
//    {
//        new_num*=10;
//    }
//    cout<<new_num<<endl;
//    if(ref==new_num)
//    {
//        cout<<"egesz szam"<<endl;
//    }
//    else
//        cout<<"nem egesz szam"<<endl;




    return 0;
}
