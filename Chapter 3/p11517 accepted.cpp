#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;

#define INF 1000000000
int memo[10010];
int coins[110],n;

int main(){
	std::ios::sync_with_stdio(false);

	int t,bill;
	cin>>t;

	while(t--){
		memset(memo,-1,sizeof(memo));

		cin>>bill>>n;
		F(i, 0, n){
			cin>>coins[i];
		}

		F(i, 0, 10010){
			memo[i] = INF;
		}

		memo[0] = 0;
        
        //All those bill values which can't be payed exactly will have INF as it's value
		F(i,0,n) {
            RF(j,10000,0) {
                if ( memo [j] != INF && j + coins [i] <= 10000 && memo [j + coins [i]] > memo [j] + 1 ){
                	memo [j + coins [i]] = memo [j] + 1;
                } 
            }
        }
 
        F(i,bill,10001) {
            if ( memo [i] != INF ) {
                cout<<i<<" "<<memo [i]<<"\n";
                break;
            }
        }
	}

	return 0;
}

/*
	WRONG SOLUTION: The code uses a single coins many times but the problem requires it to be used only once.
	Can't get it to working :(
#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;

#define INF 1000000000
int memo[10010];
int coins[110],n;
bool used[110];

int solve(int value){
	if (value <0)
	{		
		return INF;
	}

	if (value == 0)
	{
		return 0;
	}

	if (memo[value] != -1)	
	{
		return memo[value];
	}

	int returnAns = INT_MAX;
	F(i, 0,n){
		if (!used[i])
		{
			returnAns = min(returnAns , 1+ solve(value - coins[i]));	
		}
	}

	return memo[value] = returnAns;
}

int main(){
	std::ios::sync_with_stdio(false);

	int t,bill;
	cin>>t;

	while(t--){
		memset(memo,-1,sizeof(memo));
		memset(used,false,sizeof(used));
		cin>>bill>>n;
		F(i, 0, n){
			cin>>coins[i];
		}

		int ans = INF,counter=0;
		while(ans >= INF){
			ans = solve(bill+counter);
            counter++;
		}

		cout<<bill+counter-1<<" "<<ans<<"\n";
	}

	return 0;
}
*/
