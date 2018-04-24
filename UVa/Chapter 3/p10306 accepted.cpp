#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;

#define INF 1000000000

int main(){
	std::ios::sync_with_stdio(false);

	int memo[310][310];

	int n,m,s;
    cin>>n;
	while(n--){

		cin>>m>>s;

		int coin_left[m];
		int coin_right[m];

		F(i, 0, m){
			cin>>coin_left[i]>>coin_right[i];
		}
		
		//resetting the memo table
		F(i, 0, 310){
			F(j, 0, 310){
				memo[i][j]=INF;
			}
		}

		memo[0][0]=0;

		F(i, 0, m){
			F(j, coin_left[i], s+1){
				F(k, coin_right[i], s+1){
					memo[j][k] = min(memo[j][k], 1 + memo[j-coin_left[i]][k-coin_right[i]]);
				}
			}
		}

		//finding the solution from the memo table
		int ans = INF;
		F(i, 0, s+1){
			F(j, 0, s+1){
				if (i*i + j*j == s*s)
				{
					ans = min(ans, memo[i][j]);
				}
			}
		}

		if (ans == INF)		
		{
			cout<<"not possible"<<"\n";
		}else{
			cout<<ans<<"\n";
		}
	}
	
	return 0;
}



