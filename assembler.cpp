#include<bits/stdc++.h>
#include<map>
#include<fstream>
#include<string.h>

using namespace std;



string binToHex(string bin)
{
    int binaryNum, hex=0, mul=1, chk=1, rem, i=0;
   
      binaryNum = stoi(bin);
       string HEX;

      if(binaryNum == 0){

         HEX = "0";
         return HEX;

      }
     else{

char hexDecNum[20];

   
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
      // cout<<HEX<<endl;
    
    return HEX;

     }
    
}





string coMMA(string ch){
  for (int i = 0; i < ch.length(); i++)
    {
      //cout<<ch.length();
       if (ch[i] == ',' || ch[i] == ' ')
       {
         ch.erase(i);
        //  cout<<ch.length();
        //  cout<<"ggg";
       }
       
    }

    return ch;
 
  
}

int main(){


map<string,string> instrution_map {



 {"Add","0000"},
{"Addi","0001"},
{"And","0010"},
{"Or","0100"},
{"Sll","0111"},
{"Srl","1000"},
{"Jump","1001"},
{"Beq","1010"},
{"Bne","1011"},
{"Slt","1100"},
{"Slti","1101"},
{"Lw","1110"},
{"Sw","1111"},

{"$zero","000"},
{"$t0","001"},
{"$t1","010"},
{"$t2","011"},
{"$s0","`100"},
{"$s1","101"},
{"$s2","110"},
{"$s3","111"},

{"0","0000"},
{"1","0001"},
{"2","0010"},
{"3","0011"},
{"4","0100"},
{"5","0101"},
{"6","0110"},
{"7","0111"},
{"8","1000"},
{"9","1001"},
{"10","1010"},
{"11","1011"},
{"12","1100"},
{"13","1101"},
{"14","1110"},
{"15","1111"},
    

};





//ofstream machine_file;
ifstream instruction_file;

//machine_file.open("instruction.txt");

string instruction;

vector<string> v;
string c="";
string h="";

  ifstream filestream("instruction.txt");  
  if (filestream.is_open())  
  {  
    while ( getline (filestream,instruction) )  
    {  
     
      int startpos=0;
      int stringCounter=0;
      
    string machine_code;
    string hex_code;
       for (int  i = 0; i < instruction.length(); i++)
       {       
              stringCounter++;
              string substring;
             if (instruction[i] == ' ' && instruction.length()-1 != i )
             {
                substring = instruction.substr(startpos,stringCounter);
                substring = coMMA(substring);
                startpos=i+1;
                stringCounter=0;
                
               // cout<<substring<<" ";
                
                machine_code=  machine_code+instrution_map[substring];
                hex_code=  hex_code+binToHex(instrution_map[substring]);
                machine_code.append(" ");
             }
             if (i == instruction.length()-1) {
              
                 substring = instruction.substr(startpos, stringCounter);
                   substring = coMMA(substring);
                
                // cout<<substring<<"\n";
                 machine_code=  machine_code+instrution_map[substring];
                 hex_code=  hex_code+binToHex(instrution_map[substring]);
             }

             
       }


    
       c= c+ machine_code+"\n";
       h= h+ hex_code+"\n";
   

       
     
       machine_code.clear();

    }  
    filestream.close();  
  }  
  else {  
      cout << "File opening is fail."<<endl;   
    }  

    cout<<c;
    cout<<h;

    ofstream output;

    output.open("machine.txt");

    output<<c;


        ofstream hex_file;

    hex_file.open("hex.txt");

    hex_file<<h;


    
    




// fstream machine_file;

//  for (int i = 0; i < v.size(); i++) {
//         cout << v[i]<<endl;
//       machine_file.open("machine.txt");

//     if(machine_file.is_open())
//     {
//        string s = v[i];
//             for (int j = 0; j < s.length()-1; i++)
//             {
//               machine_file<<s[i];
//             }
            
       
//         machine_file.close();
//     }
//     else cout<<"Unable to open file";
//     }





    return 0;
}