#include<bits/stdc++.h>
using namespace std;


void fastscan(int &number)
{

    bool negative = false;
    register int c;
 
    number = 0;
 

    c = getchar();
    if (c=='-')
    {

        negative = true;
 

        c = getchar();
    }
 
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
 
    if (negative)
        number *= -1;
}

int main(){

    int testcase;
    fastscan(testcase);  

    int temp1;
    int temp2;

    while (testcase--)
    {   
        map<int,int> m;
        
        int players,obstacles,rolls;
        fastscan(players);
        fastscan(obstacles);
        fastscan(rolls);

        int scores[players];
        for(int i=0;i<players;i++){
            scores[i]=1;
        }
        
        for (int i = 0; i < obstacles; i++)
        {
            fastscan(temp1);
            fastscan(temp2);
            
            m[temp1]=temp2;
        }
        bool gameOn=true;
        for (int i = 0; i < rolls; i++)
        {   
            temp2=i%players;
            fastscan(temp1);
            
            if (gameOn)
            {
                scores[temp2]+=temp1;

                if (m.find(scores[temp2]) !=m.end())
                    {
                        scores[temp2]=m[scores[temp2]];
                    }
                
                if (scores[temp2]>=100)
                    {   
                        scores[temp2]=100;
                        gameOn=false;
                    }    
            }

            
        }

        for (int i = 0; i < players; i++)
        {
            printf("Position of player %d is %d.\n",i+1,scores[i]);
        }

    }     
           return 0;    
}
