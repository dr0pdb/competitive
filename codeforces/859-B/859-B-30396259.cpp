#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 1000000000
#define SIEVELIM 10000000
#define MOD 1000000000+7
#define EPS 1e-7
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

int main(){
	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin>>n;

	ll psquares[1500];
	F(i, 1, 1500){
		psquares[i-1]=i*i;
	}

	auto itr = lower_bound(psquares,psquares+1500,n);
	int gret = *itr;
	gret = (int)sqrt(gret);
	if (itr>psquares)
	{
		itr--;
	}
	int less=*itr;
	less = (int)sqrt(less);
	int k;
	if ((gret*gret)-n>n-(less*less))
	{
		 k = less;	
	}else{
		k = gret;
	} 
	ll ans;
	if (k*k<=n)
	{
		ans=k*4;
		n-=k*k;
		if(n>0){
			ans+=2;
		}
		
	}else{
		ans = 2*k + 2*(n/k);
		ans+=2;
	}
	cout<<ans;
	return 0;
}