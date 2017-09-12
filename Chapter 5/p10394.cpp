#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 1000000000
#define MOD 1000000000+7
#define EPS 1e-7
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

#define sz 20000000
bitset<sz> bs;
std::vector<pair<long long, long long> > tp;

void sieve(ll n){
	bs.set();
	bs[0]=0;
	bs[1]=0;

	for(ll i=2;i<n;i++){
		if (bs[i])
		{
			for (ll j = i*i; j < n; j+=i)
			{
				bs[j]=0;
			}
		}
	}
}

void computeTp(){
	F(i, 3, sz-2){
		if (bs[i] && bs[i+2])
		{
			tp.push_back(make_pair(i,i+2));
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	
	sieve(sz);
	computeTp();
	int n;
	while(cin>>n){
		ii ans = tp[n-1];
		cout<<"("<<ans.first<<", "<<ans.second<<")\n";
	}
	return 0;
}