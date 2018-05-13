#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
using namespace std;
string s;
int k;

void flip(int index){
    for (size_t i = index; i < index+k; i++)
    {
        if (s[i]=='+')
        {
            s[i]='-';
        }else
        {
            s[i]='+';
        }
    }
}    

int main(){

    int t;
    scanf("%d",&t);
    int count;
    
    for (size_t i = 1; i <= t; i++)
    {
        count=0;
        cin>>s;
        scanf("%d",&k);
        printf("Case #%d: ",i);
        for (size_t j = 0; j < s.length()-k+1; j++)
        {
            
            if (s[j]=='-')
            {
                flip(j);
                count++;
            }
        }
        bool isPossible=true;
        for (size_t j = s.length()-k; j < s.length(); j++)
        {
            if (s[j]!='+')
            {
                isPossible=false;
                break;
            }
        }
        if (isPossible)
        {
            printf("%d\n",count);
        }else
        {
            printf("IMPOSSIBLE\n");
        }
    }
 return 0;  
}

