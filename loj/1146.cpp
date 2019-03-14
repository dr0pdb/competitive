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

typedef pair<double,double> pdd;
pdd pt[4];
double vab,vcd=1.0, dab,dcd, vxab, vyab, vxcd, vycd;

double dist(pdd a, pdd b) {
	return sqrt((b.first - a.first)*(b.first - a.first) + (b.second - a.second)*(b.second - a.second));
}

double f(double t) {
	pdd tmp[2];
	tmp[0].first = pt[0].first + (vxab * t);
	tmp[0].second = pt[0].second + (vyab * t);
	tmp[1].first = pt[2].first + (vxcd * t);
	tmp[1].second = pt[2].second + (vycd * t);

	return dist(tmp[0], tmp[1]);
}

double norm(double a, double b) {
	return sqrt(a*a + b*b);
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin>>t;

    F(tn, 1, t+1) {
    	cout<<"Case "<<tn<<": ";
    	F(i, 0, 4) {
    		cin>>pt[i].first>>pt[i].second;
    	}

    	dab = dist(pt[0], pt[1]);
    	dcd = dist(pt[2], pt[3]);
    	if(abs(dcd) < eps) {
    		coud(dist(pt[0], pt[2]), 6); cout<<endl;
    		continue;
    	}

    	vab = dab / dcd;
    	double dxab = pt[1].first - pt[0].first;
    	double dyab = pt[1].second - pt[0].second;
    	double dxcd = (pt[3].first - pt[2].first);
    	double dycd = (pt[3].second - pt[2].second);
    	vxab = vab * (dxab / norm(dxab, dyab));
    	vyab = vab * (dyab / norm(dxab, dyab));
    	vxcd = vcd * (dxcd / norm(dxcd, dycd));
    	vycd = vcd * (dycd / norm(dxcd, dycd));

		int counter = 350;
    	double l = 0.0, r = dcd, ans = 100000.0;
	    while (counter--) {
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

	    ans = fmin(ans, f(l));
	   	coud(ans, 6);
	   	cout<<endl;
    }

    return 0;
}/*

*/