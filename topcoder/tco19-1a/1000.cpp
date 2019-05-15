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
const double eps = 1e-9;
const double PI = acos(-1.0);
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
#define ff first
#define ss second
/*----------------------------------------------------------------------*/

class EllysTicketPrices {
  public:
  	double rounds(double var) 
	{ 
	// we use array of chars to store number 
	// as a string. 
	char str[40];  

	// Print in string the value of var  
	// with two decimal point 
	sprintf(str, "%.2f", var); 

	// scan string value in var  
	sscanf(str, "%lf", &var);  

	return var;  
	} 

	double check(double mid, vector<int> C, int N, double target) {
		double sum = mid/N, prev = rounds(mid), curr;
		FOR(i, 0, C.size()) {
			curr = prev * (100 + C[i]) / 100;
			sum += curr/N;
			prev = rounds(curr);
		}

		return rounds(sum) - target;
	}

	double getPrice(int N, vector <int> C, int target) {
		double t = target;
  		double ans = 0.00, lo = 10.00, hi = 1000.00;
  		int iterations = 500;
  		while(iterations--) {
  			double mid = hi + lo / 2.0 ;
			double diff = check(mid, C, N, t);
  			if(diff > eps) {
  				hi = mid;
  			} else if(abs(diff) > eps) {
  				lo = mid;
  			} else {
  				lo = mid;
  				ans = rounds(mid);
  				break;
  			}
  		}

  		return ans;
  	}
};