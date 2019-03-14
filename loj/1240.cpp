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

typedef pair<double, pair<double,double> > ddd;
ddd pts[3];
double dx, dy, dz, nxyz;

double dist(ddd a, ddd b) {
	return sqrt((a.first - b.first)*(a.first - b.first) + 
		(a.second.first - b.second.first)*(a.second.first - b.second.first) + 
		(a.second.second - b.second.second)*(a.second.second - b.second.second));
}

double norm(double a, double b, double c) {
	return sqrt(a*a + b*b + c*c);
}

double f(double param) {
	ddd tmp;
	double d = dist(pts[0], pts[1]);

	tmp.first = pts[0].first + (dx * param * d)/ (nxyz);
	tmp.second.first = pts[0].second.first + (dy * param * d) / (nxyz);
	tmp.second.second = pts[0].second.second + (dz * param * d)/ (nxyz);

	return dist(tmp, pts[2]);
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t; 
    cin>>t;

    F(tn, 1, t+1) {
    	cout<<"Case "<<tn<<": ";
    	F(i, 0, 3) {
    		cin>>pts[i].first>>pts[i].second.first>>pts[i].second.second;
    	}

    	dx = pts[1].first - pts[0].first;
    	dy = pts[1].second.first - pts[0].second.first;
    	dz = pts[1].second.second - pts[0].second.second;
    	nxyz = norm(dx, dy, dz);

    	// deb(nxyz);
    	if(abs(nxyz) < eps) {
    		coud(dist(pts[0], pts[2]), 10);
    		cout<<endl;
    		continue;
    	}

    	double l=0.0, r=1.0, ans = 10000;
    	ans = min(f(l), f(r));
    	int counter = 1000;
    	while(counter--) {
    		double m1 = (l*2.0+r)/3.0;
        	double m2 = (l+2.0*r)/3.0;
	        double f1 = f(m1);
	        double f2 = f(m2);
	        ans = fmin(ans, f1);
	        ans = fmin(ans, f2);
	        // deb(ans);
	        if (f1 < f2)
	            r = m2;
	        else
	            l = m1;
    	}

    	coud(ans, 10); cout<<endl;
    }

    return 0;
}/*

*/