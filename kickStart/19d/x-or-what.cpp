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

const int N = 1e5+5;
int arr[N];
set<int> ones[10];

void reset() {
	FOR(i, 0, 10) {
		ones[i].clear();
	}
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t,n,q; cin>>t;
    FOR(tn, 1, t+1) {
    	cin>>n>>q;
    	reset();
    	FOR(i, 0, n) {
    		cin>>arr[i];
    		FOR(j, 0, 10) {
    			if(arr[i] & (1 << j)) {
    				ones[j].insert(i);
    			}
    		}
    	}
    	cout<<"Case #"<<tn<<":";
    	FOR(qq, 0, q) {
    		int idx, val; cin>>idx>>val;
    		FOR(j, 0, 11) {
    			if(arr[idx] & (1 << j)) {
    				ones[j].erase(idx);
    			}
    			if(val & (1 << j)) {
    				ones[j].insert(idx);
    			}
    		}
    		arr[idx] = val;
    		int parity = 0;
    		FOR(j, 0, 10) {
    			int sz = ones[j].size();
    			if(sz % 2) {
    				parity = 1 - parity;
    			}
    			
    		}
    		int ans;
    		if (parity)
            {
                int lo = 0;
                while(lo < n) {
                    int cnt = 0;
                    FOR(j, 0, 10) {
                        if(arr[lo] & (1 << j)) {
                            cnt++;
                        }
                    }
                    if (cnt % 2)
                    {
                        break;
                    }
                    lo++;
                }
                // deb(lo);
                ans = (n - lo - 1);
                int hi = n - 1;
                while(hi >= 0) {
                    int cnt = 0;
                    FOR(j, 0, 10) {
                        if(arr[hi] & (1 << j)) {
                            cnt++;
                        }
                    }
                    if (cnt % 2)
                    {
                        break;
                    }
                    hi--;
                }
                // deb(hi);
                ans = max(ans, hi);
            } else {
                ans = n;
            }
    		cout<<" "<<ans;
    	}
    	cout<<endl;
    }

    return 0;
}