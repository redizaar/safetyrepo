#include <iostream>

using namespace std;

int main()
{
    int num;
    cin>>num;
    int output[num][num];
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
        {
            output[i][j]=0;
        }
    }
    int cella=1;
    int i=0,j=-1; //j+1 első vizsgálás miatt a [0][0] cellában akarunk kezdeni nem a [0][1]ben
    while(cella!=(num*num)+1)
    {
        while(output[i][j+1]==0 && j+1!=num)
        {
            j++;
            output[i][j]=cella;
            cella++;
        }
        while(output[i+1][j]==0 && i+1!=num)
        {
            i++;
            output[i][j]=cella;
            cella++;
        }
        while(output[i][j-1]==0 && j-1>=0)
        {
            j--;
            output[i][j]=cella;
            cella++;
        }
        while(output[i-1][j]==0 && i-1>=0)
        {
            i--;
            output[i][j]=cella;
            cella++;
        }
    }
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
        {
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
