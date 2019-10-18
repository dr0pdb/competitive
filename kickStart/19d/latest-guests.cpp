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
char tp[N];
int cw[N], cc[N];
set<int> ss;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t,n,g,m,tmp; cin>>t; char c;
    FOR(tn, 1, t+1) {
    	cin>>n>>g>>m;
		memset(cw, 0, sizeof(cw)); memset(cc, 0, sizeof(cc));
    	cout<<"Case #"<<tn<<":";
    	FOR(i, 0, n) {
    		cin>>arr[i]>>tp[i]; arr[i]--;
    		if(tp[i] == 'C') {
    			int fn = (arr[i] + m%n)%n;
    			cw[fn]++;
    			ss.insert(fn);
    		} else {
    			int fn = (arr[i] - (m%n) + n)%n;
    			cc[fn]++;
    			ss.insert(fn);
    		}
    	}
    	FOR(i, 0, n) {
    		if(cc[i] || cw[i]) continue;
    		auto itr = ss.lower_bound(i);
			set<int>::iterator itr2, itr3;
    		if(itr == ss.end()) {
				itr2 = ss.begin();
				itr3 = --itr;
    		} else if(itr == ss.begin()) {
    			itr2 = itr;
    			itr = ss.end(); --itr;
    			itr3 = itr;
    		} else {
    			itr2 = itr;
    			itr3 = --itr;
    		}

    		if(abs(*itr2 - i) != abs(*itr3 - i)) {
				if(abs(*itr2 - i) < abs(*itr3 - i)) {
					cw[i] = cw[*itr2];
				} else {
					cc[i] = cc[*itr3];
				}
			} else {
				cc[i] = cc[*itr3];
				cw[i] = cw[*itr2];
			}
    	}
    	FOR(i, 0, n) {
    		cout<<" "<<(cc[i] + cw[i]);
    	}
    	cout<<endl;
    }

    return 0;
}