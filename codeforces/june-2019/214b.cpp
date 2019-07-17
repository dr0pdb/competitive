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

const int N = 1e5+1;
int dig[N];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,sm=0; cin>>n; bool zero = false;
    FOR(i, 0, n) {
    	cin>>dig[i];
    	zero |= (dig[i] == 0);
    	sm += (dig[i] % 3);
    	sm %= 3;
    }
    if(!zero) {
    	cout<<-1;
    	return 0;
    }
    string ans = "";
    sort(dig, dig+n);
    int removed = -1, removed2 = -1;
    if(sm) {
    	FOR(i, 0, n) {
    		if(dig[i]%3 == sm) {
    			removed = i;
    			break;
    		}
    	}
    	if(removed == -1) {
    		if(sm == 1) {
    			FOR(i, 0, n) {
    				if(dig[i]%3==2) {
	    				if(removed == -1) {
	    					removed = i;
	    				} else {
	    					removed2 = i;
	    					break;
	    				}
	    			}
    			}
    		} else {
    			FOR(i, 0, n) {
    				if(dig[i]%3==1) {
	    				if(removed == -1) {
	    					removed = i;
	    				} else {
	    					removed2 = i;
	    					break;
	    				}
	    			}
    			}
    		}
    	}
    }
    RFOR(i, n-1, 0) {
    	if(i == removed || i == removed2) continue;
    	ans.push_back((char)(dig[i]+'0'));
    }
    reverse(ans.begin(), ans.end());
    while(ans.size() > 1 && ans.back() == '0') ans.pop_back();
    reverse(ans.begin(), ans.end());
    cout<<ans;
    return 0;
}