
#include <iostream>

#include<string>     /* printf */
#include <assert.h> 

#include <fstream>

#include "cards.h"

#include <vector>
#include <algorithm>

using std::cout;
using namespace std;


  


int cardToInt(string card)
{
  int num = 0;
  string suit = card.substr(0,1);
  if(suit=="c")
  {
    num = 0;
  }
  else if (suit=="d")
  {
    num = 1;
  }
  else if (suit == "s")
  {
    num = 2;
    
  }

  else
  {
    num = 3;
  }





  if(card.substr(card.length() -2 , card.length())=="10")
  {
    return 10 + 15*num;
  }

  if (card.substr(card.length() -1 )=="j")
  {
    return 11 + 15*num;
  }
  if (card.substr(card.length() -1 )=="q")
  {
    return 12 + 15*num;
  }
  if (card.substr(card.length() -1 )=="k")
  {
    return 13 + 15*num;
  }
  if (card.substr(card.length() -1 )=="a")
  {
    return 1 + 15*num;
  }
  

  
  return stoi(card.substr(card.length()-1)) + 15*num;

  
}

string its(int card)
{
  int suit = card/15;

  int num = card%15;

  string s = "";
  string n = "";
  if(suit==0)
  {
    s="c";

  }
  else if (suit==1)
  {
    s="d";
  }
  else if (suit == 2)
  {
    s = "s";
    
  }

  else
  {
    s= "h";
  }

  if (num<=10)
  {
    n = to_string(num);
  }
  if (num==11)
  {
    n="j";
  }
  if (num==12)
  {
    n="q";
  }
  if (num==13)
  {
    n="k";
  }
  if (num==1)
  {
    n="a";
  }

  return s+ " " + n;

  

  
}
void play(Cards& a , Cards& b)


{



  bool matched = false;


  int curr;

  vector<int> vecta;

  vector<int> vectb;

  int counter = 0;

  string card = "";



  while(!a.empty()||!b.empty())
  {

    while(!matched && !a.empty()&&a.min()!=0&&a.max()<60)
      {
  
        curr = a.min();
        if(b.contains(curr))
        {

          
          a.remove(curr);

          b.remove(curr);

          card = its(curr);

          cout<<"Alice picked matching card "<<card<<endl;
          matched = true;
        }
        
        else
        {
          
          card = its(curr);
          vecta.push_back(curr);
          a.remove(curr);

        }
        }

        
    matched = false;
    
    while(!matched && !b.empty()&&b.max()!=0&&b.max()<60)
          {
            curr = b.max();
            
            
            if(a.contains(curr))
            {
              counter = counter + 2;
              a.remove(curr);
    
              b.remove(curr);
    
              card = its(curr);
    
              cout<<"Bob picked matching card "<<card<<endl;
              matched = true;
            }
            else
            {
              
              
              card = its(curr);
              vectb.push_back(curr);
              b.remove(curr);
            }
            
            
            }
        matched = false;
        


        

    

    
        
        
          

          
        }
  
  cout<<endl;
  cout<<"Alice's cards:"<<endl;
  reverse(vectb.begin() , vectb.end());
  //reverse(vecta.begin(), vecta.end());
  for (int x : vecta)
    {
      cout<<its(x)<<endl;
      /*
      if(cardToInt(x)>0 && cardToInt(x)<60)
      {
        cout<<x<<endl;
      }
      */
    }
  cout<<endl;
  cout<<"Bob's cards:"<<endl;
  for(int y: vectb)
    {

        cout<<its(y)<<endl;
      
    }
  
        
        
        
      }
      
  








int main(int argc, char* argv[])
{
  assert(argc==3);

  string aliceFile = argv[1];



  string bobFile = argv[2];
  string card;
  ifstream opener;

  ifstream bobopener;

  int cardNum;
  Cards a; 
  Cards b;
  

  opener.open(aliceFile);
  getline(opener , card);

  a.insert(cardToInt(card));

  while(!opener.fail())
    {
      if(card.size()>2)
      {

        cardNum = cardToInt(card);
  
        a.insert(cardNum);
      }

      getline(opener,card);
      
      
    }

  bobopener.open(bobFile);
  getline(bobopener , card);

  b.insert(cardToInt(card));

  while(!bobopener.fail())
    {
      getline(bobopener,card);

      if(card.size()>2)
      {
        cardNum = cardToInt(card);
  
        b.insert(cardNum);
        }

      
      
      
    }








  play(a,b);


  //play(a,b);


  
  return 0;
  
  

  
  
}