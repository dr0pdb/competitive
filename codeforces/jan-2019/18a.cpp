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
/*----------------------------------------------------------------------*/

bool check(int x[], int y[]) {
	int d[3];
	d[0] = (x[1]-x[0])*(x[1]-x[0]) + (y[1]-y[0])*(y[1]-y[0]);
	d[1] = (x[1]-x[2])*(x[1]-x[2]) + (y[1]-y[2])*(y[1]-y[2]);
	d[2] = (x[2]-x[0])*(x[2]-x[0]) + (y[2]-y[0])*(y[2]-y[0]);
	sort(d, d+3);
	if(d[0]<=0)
		return false;
	return (d[0] + d[1] == d[2]);
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    int x[3],y[3];
    F(i, 0, 3) {
    	cin>>x[i]>>y[i];
    }

    if(check(x, y)) {
    	cout<<"RIGHT";
    	return 0;
	}

	F(i, 0, 3) {
		x[i]++;
		bool val = check(x, y);
		x[i]-=2;
		val |= check(x, y);
		x[i]++;
		y[i]++;
		val |= check(x, y);
		y[i]-=2;
		val |= check(x, y);
		y[i]++;
		if(val) {
			cout<<"ALMOST";
			return 0;
		}

	}
	cout<<"NEITHER";

    return 0;
}/*

*/
