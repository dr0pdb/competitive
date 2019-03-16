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
const long double eps = 1e-9;
const long double PI = acos(-1.0);
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
inline void debug_vi(vi a) {F(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {F(i, 0, a.size()) cout<<a[i]<<" ";}
/*----------------------------------------------------------------------*/

long double sq(long double a) {
	return a*a;
}

long double findArea(long double a, long double b, long double c) 
{ 
    long double s = (a+b+c)/2; 
    return sqrt(s*(s-a)*(s-b)*(s-c)); 
} 

int main(){
    // std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	int t; long double in[2][3];
	cin>>t;

	F(tn, 1, t+1) {
		cout<<"Case "<<tn<<": ";
		F(i, 0, 2) {
			F(j, 0, 3) {
				cin>>in[i][j];
			}
		}

		long double ans = 0.0;
		long double d = sqrt(sq(in[0][1]-in[1][1]) + sq(in[0][0]-in[1][0]));
		if(d - in[0][2] - in[1][2] > eps) {
			coud(ans, 10); cout<<endl;
			continue;
		} else if (in[0][2] > in[1][2] + d) {
			// circle 1 inside circle 0.
			ans = PI * sq(in[1][2]);
			coud(ans, 10);
			cout<<endl;
			continue;
		} else if (in[1][2] > in[0][2] + d) {
			// circle 0 inside circle 1.
			ans = PI * sq(in[0][2]);
			coud(ans, 10);
			cout<<endl;
			continue;
		}
		long double area_trap = 2 * findArea(d, in[0][2], in[1][2]);
		long double theta1 = acos((sq(in[0][2]) + sq(d) - sq(in[1][2])) / (2*in[0][2]*d));
		long double theta2 = acos((sq(in[1][2]) + sq(d) - sq(in[0][2])) / (2*in[1][2]*d));
		
		ans = sq(in[0][2])*theta1 + sq(in[1][2])*theta2 - area_trap;
		coud(ans, 10);
		cout<<endl;
	}

    return 0;
}/*

*/