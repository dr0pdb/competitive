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

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,ans=0;
    cin>>n;

    string s,t;
    cin>>s>>t;

    F(i, 0, n/2) {
    	map<char,int> m;
    	m[s[i]]++; m[s[n-1-i]]++;
    	m[t[i]]++; m[t[n-1-i]]++;
    	if(m.size() == 1) continue;
    	if(m.size() == 4) {
    		ans += 2;
    		continue;
    	}
    	if(m.size() == 2) {
    		auto itr = m.begin();
    		int cnt1 = itr->second; ++itr;
    		int cnt2 = itr->second;
    		if(cnt1 != cnt2) {
    			ans++;
    		}
    		continue;
    	}

    	if(s[i] == s[n-1-i]) {
    		ans+=2;
    	} else {
    		ans++;
    	}
    }
    if((n & 1)) {
		if(s[n/2] != t[n/2]) ans++;
	}
    cout<<ans;

    return 0;
}/*

*/