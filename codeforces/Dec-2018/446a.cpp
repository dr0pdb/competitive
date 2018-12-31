#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define SIEVELIM 10000000+10
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
#define ull unsigned long long
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
#define deb(x )     cerr << #x << " here "<< x << endl;
#define endl    "\n"
#define printCase() "Case #" << caseNum << ": "

inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }

const ll MOD = 1000000007;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);
/*----------------------------------------------------------------------*/

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.
    int n;
    cin>>n;

    int arr[n],curr=0, prev = -1;
    vector<vi> incs;
    incs.push_back(vi());

    F(i, 0, n) {
    	cin>>arr[i];
    	if(arr[i] > prev) {
    		incs[curr].push_back(arr[i]);
    	} else {
    		incs.push_back(vi());
    		curr++;
    		incs[curr].push_back(arr[i]);
    	}
    	prev = arr[i];
    }
    curr++;

    // F(i, 0, curr) {
    // 	F(j, 0, incs[i].size()) {
    // 		cout<<incs[i][j]<<" ";
    // 	}
    // 	cout<<endl;
    // }

    int ans = 0;
    F(i, 0, curr) {
    	ans = max(ans, (int)incs[i].size());
    	if(curr > 1) {
    		ans = max(ans, (int)incs[i].size()+1);	
    	}
    }

    F(i, 0, curr-1) {
    	int a = incs[i].size(), b = incs[i+1].size();
		if(b == 1 || a == 1) {
			ans = max(ans, a+b);
			continue;
		}

		int bs = max(a, b);
		int t = incs[i+1][0]-1;
		if(t > incs[i][a-2]) {
			bs = max(ans, a+b);
		}

		t = incs[i][a-1]+1;
		if(t < incs[i+1][1]) {
			bs = max(ans, a + b);
		}
		ans = max(ans, bs);
    }
    cout<<ans;
    return 0;
}/*

*/
