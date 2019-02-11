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

const int N = 105;
int mat[N][N];
int row[N],col[N];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    int r,c,k=0;
    cin>>r>>c;
    memset(row, 0, sizeof(row)); memset(col, 0, sizeof(col));
    F(i, 0, r) {
    	F(j, 0, c) {
    		cin>>mat[i][j];
    	}
    }

    if(r <= c) {
    	F(i, 0, r) {
	    	int minm = *min_element(mat[i], mat[i]+c);
	    	row[i] += minm; k += minm;
	    	F(j, 0, c) {
	    		mat[i][j] -= minm;
	    	}
    	}

	    F(j, 0, c) {
	    	int minm = INF;
	    	F(i, 0, r) {
	    		minm = min(minm, mat[i][j]);
	    	}
	    	col[j] += minm; k+= minm;
	    	F(i, 0, r) {
	    		mat[i][j] -= minm;
	    		if(mat[i][j]) {
	    			cout<<-1;
	    			return 0;
	    		}
	    	}
	    }
    } else {
    	F(j, 0, c) {
	    	int minm = INF;
	    	F(i, 0, r) {
	    		minm = min(minm, mat[i][j]);
	    	}
	    	col[j] += minm; k+= minm;
	    	F(i, 0, r) {
	    		mat[i][j] -= minm;
	    	}
	    }

	    F(i, 0, r) {
	    	int minm = *min_element(mat[i], mat[i]+c);
	    	row[i] += minm; k += minm;
	    	F(j, 0, c) {
	    		mat[i][j] -= minm;
	    		if(mat[i][j]) {
	    			cout<<-1;
	    			return 0;
	    		}
	    	}
    	}
    }

    cout<<k<<endl;
    F(i, 0, r) {
		F(j, 0, row[i]) {
			cout<<"row "<<i+1<<endl;
		}
    }
    F(j, 0, c) {
		F(i, 0, col[j]) {
			cout<<"col "<<j+1<<endl;
		}
    }


    return 0;
}/*

*/