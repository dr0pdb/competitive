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

vector<int> A, B, C;
long long D[1024][1024] = {};

void pythagorean_triple() {
	for (int n = 1; n < 32; n++) {
		for (int m = n+1; m < 32; m += 2) {
			if (__gcd(n, m) > 1)
				continue;
			if (n * n + m * m > 1000)
				continue;
			int a = m * m - n * n;
			int b = 2 * m * n;
			int c = m * m + n * n;
			A.push_back(a);
			B.push_back(b);
			C.push_back(c);
		}
	}
}

void get_for_oblique() {
	for (int i = 0; i < A.size(); i++) {
		int a = A[i], b = B[i], c = C[i];
		while (a <= 1000 && b <= 1000) {
			for (int r1 = 1; r1 < c; r1++) {
				int r2 = c - r1;
				int w = r1 + r2 + a, h = r1 + r2 + b;
				w = max(w, max(r1 * 2, r2 * 2));
				h = max(h, max(r1 * 2, r2 * 2));
				if (w <= 1000 && h <= 1000) {
					D[w][h] += 2;
					D[h][w] += 2;
				}
			}
			a += A[i], b += B[i], c += C[i];
		}
	}
}

int main(){
    // std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	int t,h,w,N;
	cin>>t;
	pythagorean_triple();
	get_for_oblique();
	
	F(tn, 1, t+1) {
		cout<<"Case "<<tn<<": ";
		cin>>h>>w;
		N = max(h/2, w/2);

		ll ans = 0;
		F(r1, 1, N+1) {
			F(r2, 1, N+1) {
				int ht = 2*(r1 + r2), width = 2*max(r1, r2);
				if(ht <= h && width <= w)
					ans += (h - ht + 1LL) * (w - width + 1LL);
				ht = 2*max(r1, r2), width = 2*(r1 + r2);
				if(ht <= h && width <= w)	
					ans += (h - ht + 1LL) * (w - width + 1LL);
			}
		}

		// oblique
		F(i, 1, h+1) {
			F(j, 1, w+1) {
				ans += D[i][j] * (h - i + 1LL) * (w - j + 1);
			}
		}
		
		cout<<ans<<endl;
	}

    return 0;
}/*

*/