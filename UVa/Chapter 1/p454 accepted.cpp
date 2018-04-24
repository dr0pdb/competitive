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
    cin.ignore();
     

    string s,trims;

    while (testcase--)
    {   
       map<string, string > ananagram;
        int numberString=0;
        while (true)
        {   
            s="";
            getline(cin,s);
            if (!s.length())
            {
                break;
            }
            numberString++;
            trims="";
            for (int  i = 0; i < s.length(); i++)
            {
                if(s[i]!=' '){
                    trims=trims+s[i];
                }
            }
            sort(trims.begin(), trims.end());
            ananagram[s]=trims;

        }   

        

        map<string,string>::iterator i=ananagram.begin();
        while (numberString>1)
        {
            s=i->first;
            trims=i->second;

            map<string,string>::iterator j=i;
            j++;
            for (; j != ananagram.end(); j++)
            {
                if (trims == j->second)
                {
                    cout << s <<" = "<<j->first<< "\n";
                }
            }
            i++;
            numberString--;
        }
        if (testcase)
        {
            printf("\n");
        }
    }    
           return 0;    
}
