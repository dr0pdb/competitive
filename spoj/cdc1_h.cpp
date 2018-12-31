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
ll t,n,q,cn=1,st[4*N],lazy[4*N];
    
// void buildTree(int stIndex, int l, int r) {
// 	if(l == r) {
// 		st[stIndex] = 0;
// 		return;
// 	}

// 	int mid = (l + r)/2;
// 	buildTree(2*stIndex, l, mid);
// 	buildTree(2*stIndex, mid+1, r);
// 	st[stIndex] = st[2*stIndex] +  st[2*stIndex];
// }

void push(int stIndex, int tl, int mid, int tr) {
	lazy[2*stIndex] += lazy[stIndex];
	lazy[2*stIndex+1] += lazy[stIndex];
	// cout<<"Setting lazy of "<<tl<<" "<<mid<<" as "<<lazy[2*stIndex]<<endl;
	// cout<<"Setting lazy of "<<mid+1<<" "<<tr<<" as "<<lazy[2*stIndex+1]<<endl;
	st[2*stIndex] += (mid - tl + 1) * lazy[stIndex];
	st[2*stIndex+1] += (tr - mid) * lazy[stIndex];
	// cout<<"Setting st of "<<tl<<" "<<mid<<" as "<<st[2*stIndex]<<endl;
	// cout<<"Setting st of "<<mid+1<<" "<<tr<<" as "<<st[2*stIndex+1]<<endl;
	lazy[stIndex]=0;
}

ll get(int stIndex, int tl, int tr, int ql, int qr) {
	if(ql > qr) {
		return 0;
	}

	if(tl == ql && tr == qr) {
		return st[stIndex];
	}

	int mid = (tl + tr)/2;
	push(stIndex, tl, mid, tr);
	ll ret1 = get(2*stIndex, tl, mid, ql, min(qr, mid));
	ll ret2 = get(2*stIndex+1, mid+1, tr, max(ql, mid+1), qr);

	return ret1 + ret2;
}

void range_update(int stIndex, int tl, int tr, int ql, int qr) {
	if(ql > qr) 
		return;

	if(tl == ql && tr == qr) {
		// cout<<"Setting lazy of "<<tl<<" "<<tr<<" as "<<lazy[stIndex]+1<<endl;
		lazy[stIndex] += 1;
		st[stIndex] += (tr-tl+1);
		// cout<<"Setting st of "<<tl<<" "<<tr<<" as "<<st[stIndex]<<endl;
		return;
	}

	int mid = (tl + tr)/2;
	push(stIndex, tl, mid, tr);
	range_update(2*stIndex, tl, mid, ql, min(qr, mid));
	range_update(2*stIndex+1, mid+1, tr, max(ql, mid+1), qr);
	st[stIndex] = st[2*stIndex] + st[2*stIndex+1];
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.
    cin>>t;
    string query;
    int ql, qr;

	while(t--) {
		cin>>n>>q;
		memset(lazy, 0, sizeof(lazy));
		memset(st, 0, sizeof(st));

		cout<<"Scenario #"<<cn++<<":\n";
		F(i, 0, q) {
			cin>>query>>ql>>qr; ql--; qr--;
			if(query[0] == 'a') {
				cout<<get(1, 0, n-1, ql, qr)<<endl;
			} else {
				range_update(1, 0, n-1, ql, qr);
				cout<<"OK\n";
			}
		}
	}

    return 0;
}/*

*/
