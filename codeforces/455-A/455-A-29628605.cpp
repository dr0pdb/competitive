#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

#define MAXM 100005

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	cin>>n;

	ll arr[n],freq[MAXM]={0};

	F(i, 0, n){
		cin>>arr[i];
		freq[arr[i]]++;
	}

	ll dp[MAXM]={0};
	dp[1] = freq[1];
	F(i, 2, MAXM){
		dp[i] = max(dp[i-1], dp[i-2]+freq[i]*i);
	}	

	cout<<dp[MAXM-1];

	return 0;
}