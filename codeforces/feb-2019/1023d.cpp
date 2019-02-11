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

const int N = 2e5+1;
int arr[N],maxleft[N],maxright[N];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,q,par=0;
    cin>>n>>q;

    bool allzero=true;
    F(i, 0, n) {
    	cin>>arr[i];
    	if(arr[i]==0) {
    		arr[i] = par;
    	}
    	maxleft[i] = arr[i];
    	if(i) {
    		maxleft[i] = maxleft[i-1];
    	}
    	par = arr[i];
    	if(arr[i]) allzero = false;
    }

    par = 0;
    RF(i, n-1, 0) {
    	if(arr[i] == 0) {
    		arr[i] = par;
    	}
    	maxright[i] = arr[i];
    	if(i != n-1) {
    		maxright[i] = max(maxright[i], maxright[i+1]);
    	}
    	par = arr[i];
    	if(arr[i]) allzero = false;
    }

    if(allzero) {
    	cout<<"YES\n";
    	F(i, 0, n) {
    		cout<<q<<" ";
    		if(q > 1) {
    			q--;
    		}
    	}
    	return 0;
    }

    bool qpresent = false;

    F(i, 0, n) {
    	int lmax = -1;
    	if(i) {
    		lmax = maxleft[i-1];
    	2}

    	int rmax = -1;
    	if(i != n-1) {
    		rmax = maxright[i+1];
    	}

    	qpresent |= (arr[i] == q);

    	if(arr[i] < lmax && arr[i] < rmax) {
    		cout<<"NO";
    		return 0;
    	}
    }

    if(!qpresent) {
    	cout<<"NO";
    	return 0;
    }

    cout<<"YES\n";
    F(i, 0, n) {
    	cout<<arr[i]<<" ";
    }

    return 0;
}/*

*/