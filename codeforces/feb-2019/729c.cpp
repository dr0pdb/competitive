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

const int N = 2e5+1;
ii cars[N];
int g[N], n,k,s,t;
vii final_cars;

bool valid(int mid) {
	int totalt = 0, capacity = final_cars[mid].second, currx = 0;
	// deb(capacity);

	F(i, 0, k) {
		int dist = g[i] - currx;
		int ack = capacity - dist;
		if(ack < 0) return false;
		if(ack > dist) {
			ack = dist;
		}
		totalt += (2*dist - ack);
		currx = g[i];
	}

	// deb(totalt);
	int dist = s - g[k-1];
	int ack = capacity - dist;
	if(ack < 0) return false;
	if(ack > dist) {
		ack = dist;
	}
	totalt += (2*dist - ack);

	// deb(totalt);
	return totalt <= t;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    cin>>n>>k>>s>>t;

    F(i, 0, n) {
    	cin>>cars[i].first>>cars[i].second;
    }

    F(i, 0, k) {
    	cin>>g[i];
    }

    sort(g, g+k);
    sort(cars, cars + n);
    int currmaxm = -1;
    F(i, 0, n) {
    	if(cars[i].second > currmaxm) {
    		final_cars.push_back(cars[i]);
    		currmaxm = cars[i].second;
    	}
    }

    n = final_cars.size();
    int lo = 0, hi = n-1, ans=n;

    while(lo <= hi) {
    	int mid = lo + (hi - lo)/2;
    	if(valid(mid)) {
    		ans = mid;
    		hi = mid - 1;
    	} else {
    		lo = mid + 1;
    	}
    }

    if (ans == n)
    {
    	cout<<-1;
    } else {
    	cout<<final_cars[ans].first;
    }

    return 0;
}/*

*/