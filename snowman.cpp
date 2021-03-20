#include <iostream>
#include <string>
#include <array> //kontainerim le limnoa harigot
#include <cstdlib>
#include "snowman.hpp"
using namespace std;

namespace ariel {
    //le nirze leshanot lahem et hashem 
    //behemsheh kanire naase srtuct she eyaze helek ba guf shel ish sheleg
 //le rozim misparei kesem
 const int zero =0;
const int one = 1;
const int two = 2;
const int tree = 3;
const int four = 4;
const int five =5;
const int six = 6;
const int seven = 7;
const int eight = 8;
const int nine = 9;
const int ten = 10;


    string snowman(long a){
        string resoltSnowman;
       int i = 0;
       string number = to_string(a);
       if(number.size()!=eight){
           throw::out_of_range("the number is is bigger or smaller than eight");
       }
       long copy = a;
      while(copy!=0){
       int mod = copy%ten;
       if(mod>4 || mod < 1 ){
           throw::out_of_range("argument is not correct");
       } 
       copy/=ten;   
      }
       
        const int NUM_OF_OPTION = four;
        const int NUM_OF_PARTS = eight;
       // if(caunter == eight){
        long copy2 = a;
         // array<string,four> Hats = {"_===_","  ___\n ....." , "   _\n  /_\\" , "  ___\n (_*_)"}; //habrakets youdea lityahes ke maarah shel stringimg 
        // array<string,four> Nose = {",",".","_"," "}; //NORMAL DOT LINE NONE ,Nose
        // array<string,four> Left = {".","o","O","-"};//left eye ,dot ,bigger dot,closed
        // array<string,four> Right = {".","o","O","-"};//left eye ,dot ,bigger dot,closed
        // array<string,four> X = {"<" , "\\" , "/" , " "}; // left arm
        // array<string,four> Y = {">" , "/" , "\\" , " "}; // right arm
        // array<string,four> T = {" : " , "] [", "> <", "   "}; //torso
        // array<string,four> B = {" : ", "\" \"", "___" , "   "}; // base
        array<array<string, NUM_OF_OPTION>, NUM_OF_PARTS> snowmanParts = {{
            {" _===_ \n","  ___\n .....\n" , "   _\n  /_\\\n" , "  ___\n (_*_)\n"},
            {",",".","_"," "},
            {" (."," (o"," (O"," (-"},
            {".) \n","o) \n","O) \n","-) \n"},
            {"<","\\","/"," "},
            {">","/","\\"," "},
            {" ( : ) \n"," (] [) \n"," (> <) \n"," (   ) \n"},
            {" ( : ) "," (\" \") "," (___) "," (   ) "}
        }};
         long newNum = 0;
        for (size_t i = 0; i < eight; i++)
        {
            int mod = copy2%ten;
            newNum = newNum*ten + mod;
             copy2/=10;
        }
        
         array<string,eight> resolt;
         for (size_t i = 0; i < eight; i++)
         {
             long mod = newNum%ten;
             resolt.at(i)=snowmanParts.at(i).at((mod)-1); //kol hahalakim mi mishtamesh
             newNum/=ten;
         }
         resoltSnowman += resolt.at(0) + resolt.at(2) + resolt.at(1) + resolt.at(3) + resolt.at(6) + resolt.at(7);
         //mikre miuhad le yadaim
          string righhandposition;
          string lefthandposition;
          if(resolt.at(4)=="\\" ) {//kaha madpisim backslash
               lefthandposition += resolt.at(0);
                resoltSnowman.replace(lefthandposition.size() ,1,resolt.at(4));
          }
          else    //yad smol lemata
          {
              lefthandposition += resolt.at(0) + resolt.at(2) + resolt.at(1) + resolt.at(3);
                 resoltSnowman.replace(lefthandposition.size() ,1,resolt.at(4));
          }
          if(resolt.at(5)=="/" ) {//kaha madpisim backslash //yad yamin lemala
               righhandposition += resolt.at(0) + resolt.at(2) + resolt.at(1) + resolt.at(3);
                resoltSnowman.replace(righhandposition.size()-2 ,1,resolt.at(5));
          }
          else    //yad yamin lemata
          {
               righhandposition += resolt.at(0) + resolt.at(2) + resolt.at(1) + resolt.at(3)+resolt.at(6);
                 resoltSnowman.replace(righhandposition.size()-2 ,1,resolt.at(5));
          }
        

        return resoltSnowman;
   
        }
        // else
        //   {
        //       throw std::out_of_range("the input is too small must be atlease 8 digit long");
        //   }
       
    

}

