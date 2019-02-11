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

const int N = 5e5+1;
int xb[N],yb[N],n,x,y,nearest[8];
char c[N];

void update(int ind) {
	int diffx = xb[ind]-x;
	int diffy = yb[ind]-y;
	if(diffx == 0) {
		int tmp = 0;
		if(diffy < 0) tmp = 2;

		if(nearest[tmp] == -1 || abs(yb[nearest[tmp]]-y) > abs(diffy)) {
			nearest[tmp] = ind;
		}
	} else if(diffy == 0) {
		int tmp = 1;
		if(diffx < 0) tmp = 3;

		if(nearest[tmp] == -1 || abs(xb[nearest[tmp]]-x) > abs(diffx)) {
			nearest[tmp] = ind;
		}
	} else {
		if(abs(diffx) != abs(diffy)) return;
		int tmp = 7;
		if(diffx > 0 && diffy > 0) {
			tmp = 4;
		} else if (diffx > 0 && diffy < 0) {
			tmp = 5;
		} else if(diffx < 0 && diffy > 0) {
			tmp = 6;
		}

		if(nearest[tmp] == -1 || abs(xb[nearest[tmp]]-x) > abs(diffx)) {
			nearest[tmp] = ind;
		}
	}
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    memset(nearest, -1, sizeof(nearest));
    cin>>n>>x>>y;
    F(i, 0, n) {
    	cin>>c[i]>>xb[i]>>yb[i];
    	update(i);
    }
    bool attack = false;
    F(i, 0, 8) {
    	if(nearest[i] == -1) continue;
    	if(i < 4) {
    		attack |= (c[nearest[i]] == 'R' || c[nearest[i]] == 'Q');
    	} else {
    		attack |= (c[nearest[i]] == 'B' || c[nearest[i]] == 'Q');
    	}
    }

    if(attack) {
    	cout<<"YES";
    } else {
    	cout<<"NO";
    }

    return 0;
}/*

*/