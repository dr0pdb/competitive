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

const int N = 200005;
int arr[N];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,negs=0,minmneg=INF,minmnegi=-1;
    vi zeroes;
    cin>>n;

    F(i, 0, n) {
		cin>>arr[i];
    	if(arr[i] < 0) {
    		negs++;
    		if(abs(minmneg) > abs(arr[i])) {
				minmneg = arr[i];
				minmnegi = i;
    		}
    	} else if (arr[i] == 0) {
    		zeroes.push_back(i);
    	}
    }

    if(negs%2) {
    	zeroes.push_back(minmnegi);
    }

    int done = 0,sz = zeroes.size();
    RF(i, sz-1, 1) {
    	cout<<1<<" "<<zeroes[i]+1<<" "<<zeroes[i-1]+1<<endl;
    	done++;
    	if(done == n-1) {
    		break;
    	}
    }

    if(done < n-1 && zeroes.size()) {
    	done++;
    	cout<<2<<" "<<zeroes[0]+1<<endl;
    }

    int prev=-1,curr=-1;
    F(i, 0, n) {
    	if(arr[i] == 0 || (i == minmnegi && negs%2)) continue;
    	if(prev == -1) { 
    		prev = i;
    		continue;
    	}

    	curr = i;
    	cout<<1<<" "<<prev+1<<" "<<curr+1<<endl;
    	prev = curr;
    	done++;
    	if(done == n-1) break;
    }


    return 0;
}/*

*/