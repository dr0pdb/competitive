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

 	std::vector<string> v(5);
 	v[0]="Danil";
 	v[1]="Olya";
 	v[2]="Slava";
 	v[3]="Ann";
 	v[4]="Nikita";


	string s;
	cin>>s;

	int counter[5]={0};

	F(i, 0, 5){
		size_t npos = s.find(v[i]); 
		while( npos != std::string::npos){
			counter[i]++;
			if (counter[i]==2)
			{
				break;
			}
			npos = s.find(v[i], npos+1);
		}	
	}

	int cn = 0;
	bool ans = false;
	F(i, 0, 5){
		if (counter[i]==1)
		{
			cn++;
		}else if(counter[i]>=2){
		      cout<<"NO";
		      return 0;
		}
	}

	if (cn==1)
	{
		ans = true;
	}
	if (ans)
	{
		cout<<"YES";
	}else{
		cout<<"NO";
	}
	return 0;
}