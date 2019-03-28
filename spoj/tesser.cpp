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

#define MAX_N 100010

int arr[MAX_N];
char T[MAX_N];
string P;
int prefix[MAX_N], n, m; // n = size of text, m = size of pattern.

void kmpPreprocess() {
	int i = 0, j = -1; prefix[0] = -1;

	while (i < m) {
		while (j >= 0 && P[i] != P[j]) j = prefix[j];
		i++; j++;
		prefix[i] = j;
	} 
}

bool kmpSearch() {
	int i = 0, j = 0; 

	while (i < n) {
		while (j >= 0 && T[i] != P[j]) j = prefix[j];
		i++; j++;
		if (j == m) {
			return true;
		}
	}
	return false;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin>>t;

    while(t--) {
    	cin>>n;
    	FOR(i, 0, n) {
    		cin>>arr[i];
    	}
    	FOR(i, 0, n-1) {
    		char c = 'E';
    		if(arr[i+1]>arr[i]) {
    			c = 'G';
    		} else if(arr[i+1] < arr[i]) {
    			c = 'L';
    		}
    		T[i] = c;
    	}
    	n--;
    	cin>>P;
    	m = P.size();
    	kmpPreprocess();
    	if(kmpSearch()) {
    		cout<<"YES\n";
    	} else {
    		cout<<"NO\n";
    	}
    }

    return 0;
}