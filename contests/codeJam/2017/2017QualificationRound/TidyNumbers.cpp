#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
using namespace std;

int voilation=0;

bool checkTidy(string s){
    
    for (size_t i = 1; i < s.length(); i++)
    {
        if (s[i-1]>s[i])
        {
            return false;
        }
        if (s[i]!=s[voilation])
        {
            voilation=i;
        }

    }
    return true;
}

int main(){

    int t;
    scanf("%d",&t);
    
    string s;
    for (size_t i = 1; i <= t; i++)
    {
        voilation=0;
        cin>>s;
        printf("Case #%d: ",i);
        bool isTidy=checkTidy(s);
        if (isTidy)
        {
            cout<<s<<"\n";
        }else
        {
            s[voilation]-=1;
            for (size_t j = voilation+1; j < s.length(); j++)
            {
                s[j]='9';
            }

                for (size_t j = 0; j < s.length(); j++)
            {
                bool fromStart=true;
                if (s[j]=='0' && fromStart)
                {
                    continue;
                }else
                {
                    fromStart=false;
                    printf("%c",s[j]);       
                }
            }
                printf("\n");
        }

        
    }
 return 0;  
}
