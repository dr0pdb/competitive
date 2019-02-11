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
const double eps = 1e-9;
const double PI = acos(-1.0);
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
/*----------------------------------------------------------------------*/

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    int lim[3],m,v[3];
    cin>>lim[0]>>lim[2]>>m; lim[1]=0;
    F(i, 0, 3) {
    	cin>>v[i];
    }
    double curr[3];
    curr[0]=lim[0]/2.0; curr[1]=m; curr[2]=0.0;

    while(curr[1] > eps) {
    	double nxt[3],tm[3]={1.0, 1.0, 1.0};
    	F(i, 0, 3) {
    		nxt[i] = curr[i] + v[i];
    		if(v[i] > 0) {
    			tm[i] = ((lim[i]-curr[i])*1.0)/v[i]; 
    		} else if (v[i] < 0) {
    			tm[i] = (curr[i]*1.0)/abs(v[i]);
    		}
    	}

    	double minm = *min_element(tm, tm+3);
    	if(minm < 1.0) {
    		F(i, 0, 3) {
    			curr[i] += (v[i])*minm;
    			if(fabs(curr[i]-lim[i]) < eps || curr[i] < eps) {
    				v[i] *= -1;
    			}
    		}
    	} else {
    		F(i, 0, 3) {
    			curr[i]=nxt[i];
    		}
    	}

    	if(curr[1] < eps) {
			cout<<fixed<< showpoint << setprecision(10);
			cout<<curr[0]<<" "<<curr[2];
			return 0;
		}
    }


    return 0;
}/*

*/
