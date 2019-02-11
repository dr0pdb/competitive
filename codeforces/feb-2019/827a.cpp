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

const int N = 1000005;
string ans(N, '-');
set<int> unused;
int maxm = 0;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;

    string s;
    int start,times;

    F(i, 0, n) {
    	cin>>s>>times;

    	F(j, 0, times) {
    		cin>>start;
    		start--;
    		int endi = start + (int)s.size();
    		
    		if(endi > maxm) {
    			F(k, maxm, endi) {
    				unused.insert(k);
    			}
    			maxm = endi;
    		}

    		auto itr = unused.lower_bound(start);

	    	if(itr != unused.end()) {
	    		auto itr2 = itr;
	    		while(itr2 != unused.end() && *itr2 < endi) {
	    			int ind = *itr2 - start;
	    			ans[*itr2] = s[ind]; 
	    			++itr2;
	    		}

	    		while(itr != unused.end() && *itr < endi) {
	    			itr = unused.erase(itr);
	    		}
	    	}
    	}
    }

    F(i, 0, maxm) {
    	if(ans[i] == '-') {
    		ans[i] = 'a';
    	}
    	cout<<ans[i];
    }

    return 0;
}/*

*/