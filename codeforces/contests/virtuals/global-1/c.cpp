#include<bits/stdc++.h>
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
#define ull unsigned long long
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> lll;
#define deb(x )     cerr << #x << " here "<< x << endl;
#define endl    "\n"
#define printCase() "Case #" << caseNum << ": "
inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }
const ll MOD = 1000000007;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
inline void debug_vi(vi a) {F(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {F(i, 0, a.size()) cout<<a[i]<<" ";}
/*----------------------------------------------------------------------*/

int getDivisors(ll n) 
{ 
	vll facts;
	facts.push_back(1);
    for (ll i=2; i<=sqrt(n); i++) 
    { 
        if (n%i == 0)
        { 
            if (n/i == i) 
            	facts.push_back(i);     
  
            else {
            	facts.push_back(i);
            	facts.push_back(n/i);
            }    
        } 
    }
    sort(facts.begin(), facts.end());
    return facts.back();
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int q,a;
    cin>>q;

    while(q--) {
    	cin>>a;
    	int fzero=35,lastone=-1;
    	for (int i = 0; i < 32; ++i)
    	{
    		if(a & (1 << i)) {
    			lastone = i;
    		} else if(fzero == 35) {
    			fzero = i;
    		}
    	}

    	if(fzero > lastone) {
    		cout<<getDivisors(a);
    	} else {
    		int ans = 0;
    		for(int i = 0; i <= lastone; i++) {
    			ans |= (1 << i);
    		}
    		cout<<ans;
    	}
    	cout<<endl;
    }


    return 0;
}/*

*/