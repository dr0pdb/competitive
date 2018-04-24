#include<bits/stdc++.h>

 #define sz(a) int((a).size()) 
 #define pb push_back 
 #define all(c) (c).begin(),(c).end() 
 #define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
 #define present(c,x) ((c).find(x) != (c).end()) 
 #define cpresent(c,x) (find(all(c),x) != (c).end()) 

#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j, n) for (int i = j; i < n; i++)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
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

    int mon, numd, x;
    double dp, loan, currDepr, worth, mp;

    while(true) {
        double depr[101] = {};
        
        cin >> mon >> dp >> loan >> numd;
        if(mon < 0) break;
        worth = dp + loan;
        mp = loan/mon;
        FOR0(i,numd) {
            cin >> x;
            cin >> depr[x];
        }

        currDepr = depr[0];
        worth *= 1 - currDepr;
    
        int m = 0;
        while(loan > worth) {
            m++;
            if(depr[m] > 0) {currDepr = depr[m]; }
            worth *= 1-currDepr;
            loan -= mp;
        }
            cout << m << " month";
            if(m != 1) cout << "s";
            cout << endl;
    } 
    
           return 0;    
}
