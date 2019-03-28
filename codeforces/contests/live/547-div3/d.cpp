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

const int N = 150001;
char l[N],r[N];
vector<int> ml[256],mr[256];
int startl[256],startr[256];
int fa[256],fb[256];
vii ans;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    memset(fa, 0, sizeof(fa));
    memset(fb, 0, sizeof(fb));
    memset(startl, 0, sizeof(startl));
    memset(startr, 0, sizeof(startr));

    FOR(i, 0, n) {
    	cin>>l[i];
    	ml[l[i]].push_back(i);
    	fa[l[i]]++;
    }
    FOR(i, 0, n) {
    	cin>>r[i];
    	mr[r[i]].push_back(i);
    	fb[r[i]]++;
    }

    int cnt = 0, question_index = '?';
    FOR(i, 0, 256) {
    	if(i != question_index) {
    		int adder = min(fa[i], fb[i]);
    		cnt += adder;
    		fa[i] -= adder;
    		fb[i] -= adder;
			while(adder--) {
				ans.push_back({ml[i][startl[i]], mr[i][startr[i]]});
				startl[i]++;
				startr[i]++;
			}
    	}
    }

	FOR(i, 0, 256) {
		if(i != question_index) {
			int adder = min(fa[i], fb[question_index]);
			if(adder > 0) {
				cnt += adder;
				fa[i] -= adder;
				fb[question_index] -= adder;
				while(adder--) {
					ans.push_back({ml[i][startl[i]], mr[question_index][startr[question_index]]});
					startl[i]++;
					startr[question_index]++;
				}
			}

			adder = min(fa[question_index], fb[i]);
			if(adder > 0) {
				cnt += adder;
				fa[question_index] -= adder;
				fb[i] -= adder;
				while(adder--) {
					ans.push_back({ml[question_index][startl[question_index]], mr[i][startr[i]]});
					startl[question_index]++;
					startr[i]++;
				}
			}
		}
	}

	int adder = min(fa[question_index], fb[question_index]); 
	if(adder > 0) {
		cnt += adder;
		while(adder--) {
			ans.push_back({ml[question_index][startl[question_index]], mr[question_index][startr[question_index]]});
			startl[question_index]++;
			startr[question_index]++;
		}
	}

	cout<<cnt<<endl;
	FOR(i, 0, cnt) {
		cout<<ans[i].ff+1<<" "<<ans[i].ss+1<<endl;
	}

    return 0;
}