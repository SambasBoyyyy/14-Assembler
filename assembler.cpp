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
  
       if (ch[i] == ',' || ch[i] == ' ')
       {
         ch.erase(i);
 
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
{"J","1001"},
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









ifstream instruction_file;



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
            
               if(instrution_map[substring].length() == 4 || instrution_map[substring].length() == 3 ){

                machine_code=  machine_code+instrution_map[substring];

                if (substring == "J")
               {
                 machine_code=  machine_code+"0000";
               }
            ;
               }
               
               else if (instrution_map[substring].length() !=4 && (substring == "Sll" || substring == "Srl"))
               {
                 machine_code=  machine_code+instrution_map[substring]+"1";
               }
               else{
                 machine_code=  machine_code+instrution_map[substring]+"0";
               }
               
                
                
               
             }
             if (i == instruction.length()-1) {
              
                 substring = instruction.substr(startpos, stringCounter);
                   substring = coMMA(substring);
                
                
                if(instrution_map[substring].length() == 4 ){

                machine_code=  machine_code+instrution_map[substring];
               
               }
                
               else if (instrution_map[substring].length() !=4 && (substring == "Sll" || substring == "Srl"))
               {
                 machine_code=  machine_code+instrution_map[substring]+"1";
               }
               else{
                 machine_code=  machine_code+instrution_map[substring]+"0";
               }
               
                
             }

             
       }

         
         
       machine_code=  "00"+machine_code;
       c= c+ machine_code+"\n";
     
   

       
     
       machine_code.clear();

    }  
    filestream.close();  
  }  
  else {  
      cout << "File opening is fail."<<endl;   
    }  

    cout<<c;

    vector<char> l;
   

    for (int i = 0; i < c.length(); i++)
    {
      if(c[i] != '\n'){
        l.push_back(c[i]);
      }
    }
    
int manager = 0;
    for (int i = 0; i < l.size(); i=i+4)
    {
      string tem;

      for (int j = 0; j < 4; j++)
      {
        tem.push_back(l[i+j]);
      }
      if (manager == 3)
      {
          h= h+ binToHex(tem)+'\n';
          manager =0;
      }
       else{ 
        
        h= h+ binToHex(tem);
         manager++;

       }
        
 
      
    }


    cout<<h;
    
    
 

    ofstream output;

    output.open("machine.txt");

    output<<c;


        ofstream hex_file;

    hex_file.open("hex.txt");

    hex_file<<h;


    

    return 0;
}