#include <iostream>

using namespace std;
int main()
{
    int szam;
    int cella=1;
    cin>>szam;
    int output[szam][szam];
    int sor=0;
    int oszlop=0;
    int kor=0;
    for(int i=0;i<szam;i++)
    {
        for(int j=0;j<szam;j++)
        {
            output[i][j]=0;
        }
    }
    while(cella!=((szam*szam)+1))
    {
        if(kor>=1)
        {
            if(kor==1)
                sor++; //for(;sor>0;sor--)  az elso kor után (széle feltöltés) nem a nulladik sorba akarunk lenni hanem az elsőben
                       //de az utolsó lépésnél nem az első sorban akarunk lenni hanem az aktuálisban
            while(output[sor][oszlop+1]==0)
            {
                oszlop++;
                output[sor][oszlop]=cella;
                cella++;
            }
            while(output[sor+1][oszlop]==0)
            {
                sor++;
                output[sor][oszlop]=cella;
                cella++;
            }
            while(output[sor][oszlop-1]==0)
            {
                oszlop--;
                output[sor][oszlop]=cella;
                cella++;
            }
            while(output[sor-1][oszlop]==0)
            {
                sor--;
                output[sor][oszlop]=cella;
                cella++;
            }
        }
        else
        {
            for(oszlop=0;oszlop<szam-1;oszlop++)
            {
                output[sor][oszlop]=cella;
                cella++;
            }
            for(sor=0;sor<szam-1;sor++)
            {
                output[sor][oszlop]=cella;
                cella++;
            }
            for(;oszlop>0;oszlop--)
            {
                output[sor][oszlop]=cella;
                cella++;
            }
            for(;sor>0;sor--)
            {
                output[sor][oszlop]=cella;
                cella++;
            }
        }
        kor++;
    }
    for(int i=0;i<szam;i++)
    {
        for(int j=0;j<szam;j++)
        {
            cout<<output[i][j]<<"  ";
        }
        cout<<endl;
    }
    return 0;
}
