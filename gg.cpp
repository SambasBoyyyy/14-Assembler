#include<bits/stdc++.h>
#include<map>
#include<fstream>
#include<string.h>

using namespace std;

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
{"Sub","0001"},
{"Addi","0010"},
{"$zero","000"},
{"$t0","001"},
{"$t1","010"},
{"$zero","000"},
{"$t0","001"},
{"$t1" , "010"},
{"$t2" , "011"},
{"$s0" ,"100"},
{"$s1" , "101"},
{"$s2" , "110"},
{"$s3" ,"111"},
{"0","0000"},
{"5","0101"},  
        // "0010" -> "2"
        // "0011" -> "3"
        // "0100" -> "4"
        // "0101" -> "5"
        // "0110" -> "6"
        // "0111" -> "7"
        // "1000" -> "8"
        // "1001" -> "9"
        // "1010" -> "a"
        // "1011" -> "b"
        // "1100" -> "c"
        // "1101" -> "d"
        // "1110" -> "e"
        // "1111" -> "f"

};





//ofstream machine_file;
ifstream instruction_file;

//machine_file.open("instruction.txt");

string instruction;

vector<string> v;

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
                
                //cout<<substring<<" ";
                
                v.push_back(instrution_map[substring]);
            
             }
             if (i == instruction.length()-1) {
              
                 substring = instruction.substr(startpos, stringCounter);
                   substring = coMMA(substring);
                 //cout<<substring<<"\n";
               v.push_back(instrution_map[substring]);
             }

             
       }


       // cout<<machine_code<<endl;
      //  cout<<machine_code.length()<<endl;

    
       machine_code.clear();

    }  
    filestream.close();  
  }  
  else {  
      cout << "File opening is fail."<<endl;   
    }  

fstream machine_file;

 for (int i = 0; i < v.size(); i++) {
        cout << v[i]<<endl;
      machine_file.open("machine.txt");
machine_file<<v[i];
    // if(machine_file.is_open())
    // {
     
              
            
            
       
         machine_file.close();
    // }
    // else cout<<"Unable to open file";
     }





    return 0;
}