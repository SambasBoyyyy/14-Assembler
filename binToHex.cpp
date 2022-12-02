#include<iostream>
using namespace std;


string binToHex(string bin)
{
    int binaryNum, hex=0, mul=1, chk=1, rem, i=0;
   
      binaryNum = stoi(bin);

    char hexDecNum[20];

    string HEX;
  
   
    while(binaryNum!=0)
    {
        rem = binaryNum%10;
        hex = hex + (rem*mul);
        if(chk%4==0)
        {
            if(hex<10)
                hexDecNum[i] = hex+48;
            else
                hexDecNum[i] = hex+55;
            mul = 1;
            hex = 0;
            chk = 1;
            i++;
        }
        else
        {
            mul = mul*2;
            chk++;
        }
        binaryNum = binaryNum/10;
    }
    if(chk!=1)
        hexDecNum[i] = hex+48;
    if(chk==1)
        i--;
   
    for(i=i; i>=0; i--){
       HEX = HEX+hexDecNum[i];
    }
       //cout<<HEX<<endl;
    
    return HEX;
}






int main()
{
   string s;
   cin>>s;
   cout<<binToHex(s);
    return 0;
}