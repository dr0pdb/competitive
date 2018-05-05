#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);
	
	ll n,m;
	cin>>n>>m;
	ll arr[n][m];

	F(i, 0, n){
		F(j, 0, m){
			cin>>arr[i][j];
		}
	}

	ll rows[2]={0};
	ll cols[2]={0};
	ll counter=0;

	F(i, 0, n){
		rows[1]=0;
		rows[0]=0;
		F(j, 0, m){
			
			if (arr[i][j]==1)
			{
				rows[1]++;
			}else{
				rows[0]++;
			}
		}
		counter+=(1ll<<rows[1])-1;
		counter+=(1ll<<rows[0])-1;
	}

	F(j, 0, m){
		cols[1]=0;
		cols[0]=0;
		F(i, 0, n){
			
			if (arr[i][j]==1)
			{
				cols[1]++;
			}else{
				cols[0]++;
			}
		}
		counter+=(1ll<<cols[1])-1;
		counter+=(1ll<<cols[0])-1;
	}

    counter-=n*m;
	cout<<counter;

	return 0;
}