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
ll arr[N],sum = 0, csum = 0;
set<ll> s;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    FOR(i, 0, n) {
    	cin>>arr[i]; sum += arr[i];
    }
    if(sum % 2) {
    	cout<<"NO";
    	return 0;
    }
    sum /= 2;
    FOR(i, 0, n) {
    	csum += arr[i];
    	if(csum == sum) {
    		cout<<"YES";
    		return 0;
    	} else if(csum > sum) {
    		ll diff = csum - sum;
    		if(s.find(diff) != s.end()) {
    			cout<<"YES";
    			return 0;
    		}
    	}
    	s.insert(arr[i]);
    }
    csum = 0; s.clear();
    RFOR(i, n-1, 0) {
    	csum += arr[i];
    	if(csum == sum) {
    		cout<<"YES";
    		return 0;
    	} else if(csum > sum) {
    		ll diff = csum - sum;
    		if(s.find(diff) != s.end()) {
    			cout<<"YES";
    			return 0;
    		}
    	}
    	s.insert(arr[i]);
    }
    cout<<"NO";

    return 0;
}