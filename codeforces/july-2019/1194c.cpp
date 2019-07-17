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

int freq[26];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int q; string s,t,p;
    cin>>q;
    while(q--) {
    	cin>>s>>t>>p;
    	memset(freq, 0, sizeof(freq));
    	FOR(i, 0, p.size()) {
    		freq[p[i]-'a']++;
    	}
    	int idx = 0,n = s.size();
    	bool valid = true;
    	FOR(i, 0, t.size()) {
    		if(idx < n && s[idx] == t[i]) {
    			idx++; continue;
    		}
    		if(freq[t[i]-'a']) {
    			freq[t[i]-'a']--;
    		} else {
    			valid = false;
    			break;
    		}
    	}
    	if(idx != n) valid = false;
    	if(valid) {
    		cout<<"yes\n";
    	} else {
    		cout<<"no\n";
    	}
    }

    return 0;
}