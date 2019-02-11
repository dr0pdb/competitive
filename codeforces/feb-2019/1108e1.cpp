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
inline void debug_vi(vi a) {F(i, 0, a.size()) cout<<a[i]+1<<" ";}
inline void debug_vll(vll a) {F(i, 0, a.size()) cout<<a[i]<<" ";}
/*----------------------------------------------------------------------*/

const int N = 305;
int arr[N],restore[N];
ii segs[N];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,m,ans=INT_MIN;
    cin>>n>>m;

    F(i, 0, n) {
    	cin>>arr[i];
    	restore[i] = arr[i];
    }

    F(i, 0, m) {
    	cin>>segs[i].first>>segs[i].second;
    	segs[i].first--;
    	segs[i].second--;
    }

    vi used,ans_used;
    F(i, 0, n) {
    	F(j, 0, n) {
    		arr[j] = restore[j];
    	}
    	used.clear();

    	F(j, 0, m) {
    		if(segs[j].first <= i && segs[j].second >= i) {
    			used.push_back(j);
    			F(k, segs[j].first, segs[j].second+1) {
    				arr[k]--;
    			}
    		}
    	}

    	int maxm = *max_element(arr, arr + n);
    	int minm = *min_element(arr, arr + n);
    	if(maxm - minm > ans) {
    		ans = maxm - minm;
    		ans_used = used;
    	}
    }

    cout<<ans<<endl<<ans_used.size()<<endl;
    debug_vi(ans_used);

    return 0;
}/*

*/