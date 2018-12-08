#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 1000000000
#define SIEVELIM 10000000+10
#define MOD 1000000000+7
#define EPS 1e-7
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
inline int nextint(){ int temporary; scanf("%d",&temporary); return temporary; }
inline ll nextll(){ ll temporary; scanf("%lld",&temporary); return temporary; }
inline double nextdouble(){double temporary; scanf("%lf",&temporary); return temporary;}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
int leftChild(int p ){return p<<1;}
int rightChild(int p ){return (p<<1)+1;}
inline ll mid(ll l, ll r){ return (l+r)/2;}
/*----------------------------------------------------------------------*/

int main(){
 	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

 	string s;
 	cin>>s;

 	vi acount(s.size(),0),bcount(s.size(),0),revacount(s.size(),0);
	
 	F(i, 0, s.size()){
 		if (i)
 		{
 			acount[i] = acount[i-1];
 			bcount[i] = bcount[i-1];
 		}

 		if (s[i]=='a')
 		{
 			acount[i]++;
 		}else{
 			bcount[i]++;
 		}
 	}

 	RF(i, s.size()-1, 0){
 		if (i!=s.size()-1)
 		{
 			revacount[i] = revacount[i+1];
 		}

 		if (s[i]=='a')
 		{
 			revacount[i]++;
 		}
 	}

 	ll ans = -1;

 	F(i, -1, s.size()){
 		F(j, i, s.size()){
 			ll temp =0;
 			if (i>=0)
 			{
 				temp += acount[i];
 			}
			if (j>=0)
			{
				temp += bcount[j];
				if (i>=0)
				{
					temp -=bcount[i];
				}
			}

			if (j!=s.size()-1)
			{
				temp += revacount[j+1];
			}
			ans = max(ans,temp);
 		}
 	}
 	cout<<ans;
	return 0;
}