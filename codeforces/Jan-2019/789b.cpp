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

set<ll> s;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    ll b1,q,l,m,a; cin>>b1>>q>>l>>m;
    F(i, 0, m) {
    	cin>>a;
    	s.insert(a);
    }

    if(abs(b1) > l) {
    	cout<<0;
    	return 0;
    } else if(b1 == 0) {
    	if(s.find(0) == s.end()) {
    		cout<<"inf";
    	} else {
    		cout<<0;
    	}
    	return 0;
    }

    if(q == 0) {
    	if(s.find(0) != s.end()) {
    		int cnt = 0;
    		if(s.find(b1) == s.end()) {
    			cnt++;
    		}

    		cout<<cnt;
    	} else {
    		// write 0s.
    		cout<<"inf";
    	}
    	return 0;
    } else if(q == 1) {
    	if(s.find(b1) == s.end()) {
			cout<<"inf";
		} else {
			cout<<0;
		}
		return 0;
    } else if (q == -1) {
    	if((s.find(b1) == s.end() || s.find(-b1) == s.end())) {
    		cout<<"inf";
    	} else {
    		cout<<0;
    	}
    	return 0;
    }

    ll curr = b1, ans=0;
    while(abs(curr) <= l) {
    	if(s.find(curr) == s.end()) {
    		ans++;
    		if(ans > INF) {
    			cout<<"inf";
    			return 0;
    		}
    	}
    	curr *= q;
    }
    cout<<ans;

    return 0;
}/*

*/
