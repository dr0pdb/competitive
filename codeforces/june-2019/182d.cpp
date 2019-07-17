#include<bits/stdc++.h>
#define FOR(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RFOR(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
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
inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
#define ff first
#define ss second
/*----------------------------------------------------------------------*/

vi getDivisors(int n) 
{ 
	vi facts;
    for (int i=1; i<=sqrt(n); i++) 
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
    return facts;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s1,s2; int a,b;
    cin>>s1>>s2; a = s1.size(); b = s2.size();
    int g = __gcd(a, b);
    vi divs = getDivisors(g);
    int ans = 0;
    for(int d : divs) {
    	bool good = true;
    	FOR(i, 0, d) {
    		good &= (s1[i] == s2[i]);
    	}
    	if(!good) continue;
    	FOR(i, d, s1.size()) {
    		if(s1[i] != s1[i%d]) {
    			good = false;
    			break;
    		}
    	}
    	if(good) {
    		FOR(i, d, s2.size()) {
    			if(s2[i] != s2[i%d]) {
    				good = false;
    				break;
    			}
    		}
    		if(good) ans++;	
    	}
    }
    cout<<ans;
    return 0;
}