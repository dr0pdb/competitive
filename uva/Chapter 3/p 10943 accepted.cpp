#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

#define MOD 1000000	

int main(){
	std::ios::sync_with_stdio(false);
	ll c[210][210]={0}; // contains the n choose k values.
	int n,k;

	//calculating all at once
	c[0][0]=1;
	F(i, 1, 210){
		c[i][0]=1;
		F(j, 1, i+1){
			c[i][j] = (c[i-1][j-1]%MOD + (c[i-1][j])%MOD)%MOD; 
		}	
	}


	while(cin>>n>>k && n && k){
		cout<<c[n+k-1][n]<<"\n";
	}
	return 0;
}

