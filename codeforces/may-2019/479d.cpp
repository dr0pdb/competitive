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
ii xpos, ypos;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,l,x,y,j;
    cin>>n>>l>>x>>y; xpos = {-1, -1}; ypos = xpos;
    FOR(i, 0, n) {
    	cin>>arr[i];
    }
    j = 0;
    FOR(i, 0, n) {
    	while(j < n && arr[j] - arr[i] < x) j++;
    	if(j < n && arr[j] - arr[i] == x) {
    		xpos = {i, j};
    		break;
    	}
    }
    j = 0;
    FOR(i, 0, n) {
    	while(j < n && arr[j] - arr[i] < y) j++;
    	if(j < n && arr[j] - arr[i] == y) {
    		ypos = {i, j};
    		break;
    	}
    }
    if (xpos.ff != -1 && ypos.ff != -1)
    {
    	cout<<0;
    } else if(xpos.ff != -1 || ypos.ff != -1){
    	cout<<1<<endl;
    	if(xpos.ff != -1) {
    		cout<<y;
    	} else {
    		cout<<x;
    	}
    } else {
    	j = 0;
	    FOR(i, 0, n) {
	    	while(j < n && arr[j] - arr[i] < x + y) j++;
	    	if(j < n && arr[j] - arr[i] == x+y) {
	    		cout<<1<<endl;
	    		cout<<arr[i] + x << endl;
	    		return 0;
	    	}
	    }
	    j = 0;
	    FOR(i, 0, n) {
	    	while(j < n && arr[j] - arr[i] < y - x) j++;
	    	if(j < n && arr[j] - arr[i] == y - x) {
	    		if(arr[i] - x >= 0) {
	    			cout<<1<<endl;
	    			cout<<arr[i]-x;
	    			return 0;
	    		} else if (arr[j] + x <= l) {
	    			cout<<1<<endl;
	    			cout<<arr[j]+x;
	    			return 0;
	    		}
	    	}
	    }
	    cout<<2<<endl;
	    cout<<x<<" "<<y;
    }
    return 0;
}