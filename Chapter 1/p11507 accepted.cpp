#include<bits/stdc++.h>
using namespace std;


void fastscan(long long &number)
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

    long long length;
      
    map<string, map<string, string> > possibilities;

    possibilities["+x"]["+y"]="+y";
    possibilities["+x"]["+z"]="+z";
    possibilities["+x"]["-y"]="-y";
    possibilities["+x"]["-z"]="-z";

    possibilities["-x"]["+y"]="-y";
    possibilities["-x"]["-y"]="+y";
    possibilities["-x"]["+z"]="-z";
    possibilities["-x"]["-z"]="+z";
    
    possibilities["+y"]["+y"]="-x";
    possibilities["+y"]["-y"]="+x";
    possibilities["+y"]["+z"]="+y";
    possibilities["+y"]["-z"]="+y";

    possibilities["-y"]["+y"]="+x";
    possibilities["-y"]["-y"]="-x";
    possibilities["-y"]["+z"]="-y";
    possibilities["-y"]["-z"]="-y";
    
    possibilities["+z"]["+y"]="+z";
    possibilities["+z"]["-y"]="+z";
    possibilities["+z"]["+z"]="-x";
    possibilities["+z"]["-z"]="+x";

    possibilities["-z"]["+y"]="-z";
    possibilities["-z"]["-y"]="-z";
    possibilities["-z"]["+z"]="+x";
    possibilities["-z"]["-z"]="-x";
    

     while (true)
    {
        scanf("%lld",&length);

        if (length==0)
        {
            break;
        }
        
        string direction="+x";
        string movement;
        for (long long i = 0; i < length-1; i++)
        {
            cin>>movement;
            if (movement !="No")
            {
                direction=possibilities[direction][movement];    
            }
            
        }

        cout<<direction<<"\n";
    }    
    

    
           return 0;    
}
