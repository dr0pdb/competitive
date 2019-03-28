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

const int N = 2e5+5;
int a[N],d[N];
bool pres[N];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;

    memset(a, 0, sizeof(a));
    FOR(i, 0, n-1) {
    	cin>>d[i];
    }

    a[0]=0;
    int minm=0, mini=0;
    FOR(i, 1, n) {
    	a[i] += d[i-1] + a[i-1];
    	if(a[i] < minm) {
    		minm = a[i];
    		mini = i;
    	}
    }

    memset(pres, false, sizeof(pres));
    FOR(i, 0, n) {
    	a[i] -= minm; a[i]++;
    	if(a[i] >= 1 && a[i] <= n) {
    		pres[a[i]]=true;
    	}
    }

    bool ans = true;
    FOR(i, 1, n+1) {
    	if(!pres[i]) {
    		cout<<-1;
    		return 0;
    	}
    }

    FOR(i, 0, n) {
    	cout<<a[i]<<" ";
    }


    return 0;
}