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

const int N = 100002;
ll k,n,m,st[4*N][6],arr[N][6];

void buildTree(int stIndex, int l, int r) {
	if(l == r) {
		F(i, 0, m) {
			st[stIndex][i] = arr[l][i];
		}
		return;
	}

	int mid = (l + r)/2;
	buildTree(2*stIndex, l, mid);
	buildTree(2*stIndex+1, mid+1, r);
	F(i, 0, m) {
		st[stIndex][i] = max(st[2*stIndex][i], st[2*stIndex+1][i]); 
	}
}

vi get(int stIndex, int tl, int tr, int ql, int qr) {
	if(ql > qr) {
		vi ret(m, -1);
		return ret;
	}

	if(tl == ql && tr == qr) {
		vi vals(m);
		F(i, 0, m) {
			vals[i] = st[stIndex][i];
		}
		return vals;
	}

	int mid = (tl + tr)/2;
	vi ret1 = get(2*stIndex, tl, mid, ql, min(qr, mid));
	vi ret2 = get(2*stIndex+1, mid+1, tr, max(ql, mid+1), qr);

	F(i, 0, m) {
		ret1[i] = max(ret1[i], ret2[i]);
	}

	return ret1;
}

bool valid(vi &vals) {
	int ret = 0;
	F(i, 0, m) {
		ret += vals[i];
	}

	return ret <= k;
}

int main(){
    // std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.
	scanf("%lld %lld %lld", &n, &m, &k);
	F(i, 0, n) {
		F(j, 0, m) {
			cin>>arr[i][j];
		}
	}

	buildTree(1, 0, n-1);
	ll r=0,best_size=0,curr=0;
	vi bestv(m, 0);
	F(l, 0, n) {
		r = max(l, r);
		while(r < n) {
			vi vals = get(1, 0, n-1, l, r);
			if(valid(vals)) {
				if(best_size < (r - l + 1)) {
					best_size = r - l + 1;
					bestv = vals;
					// cout<<"best for "<<l<<" "<<r<<endl;
				}
				r++;
			} else {
				break;
			}
		}
	}
	F(i, 0, m) {
		if(i)
			cout<<" ";
		cout<<bestv[i];
	}

    return 0;
}/*

*/
