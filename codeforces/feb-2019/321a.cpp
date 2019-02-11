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

int a,b,dx=0,dy=0;

bool check(int cx, int cy) {
	// deb(cx); deb(cy);
	int k1 = -1, k2 = -1;

	if(dx) {
		if((a-cx)%dx != 0) return false;
		k1 = (a - cx) / dx;
		if(k1 < 0) return false;
	}

	if(dy) {
		if((b-cy)%dy != 0) return false;
		k2 = (b - cy) / dy;
		if(k2 < 0) return false;
		if(dx) {
			return k1 == k2;
		}
	}

	if((k1 >= 0 || cx == a) && (k2 >= 0 || cy == b)) return true;
	return false;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>a>>b;
    string s;
    cin>>s;

    F(i, 0, s.size()) {
    	if(s[i] == 'U') {
    		dy++;
    	} else if (s[i] == 'D') {
    		dy--;
    	} else if(s[i] == 'L') {
    		dx--;
    	} else {
    		dx++;
    	}
    }

    int cx=0,cy=0;
    bool ans = false;
    F(i, -1, s.size()) {
    	if(i>=0) {
    		if(s[i] == 'U') {
	    		cy++;
	    	} else if (s[i] == 'D') {
	    		cy--;
	    	} else if(s[i] == 'L') {
	    		cx--;
	    	} else {
	    		cx++;
	    	}
    	}

    	ans |= (cx == a && cy == b);
    	ans |= check(cx, cy);
    	if(ans) {
    		// deb(i);
    		break;
    	}
    }

    if(ans) {
    	cout<<"Yes";
    } else {
    	cout<<"No";
    }

    return 0;
}/*

*/