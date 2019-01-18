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
int arr[N],n,status[N],ind=0; 
ii cstart[N];

void get_cycle(int start) {
	int next = arr[start];
	cstart[ind].first=start;
	cstart[ind].second=1;
	while(next != start) {
		cstart[ind].second++;
		next = arr[next];
	}
	ind++;
}

void dfs(int curr) {
	status[curr]=2;
	int next = arr[curr];
	if(status[next] == 0) {
		dfs(next);
	} else if(status[next] == 2) {
		get_cycle(next);
	}

	status[curr]=1;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n;
    F(i, 0, n) {
    	cin>>arr[i];
    	arr[i]--;
    }
    memset(status, 0, sizeof(status));
    F(i, 0, n) {
    	if(!status[i]) {
    		dfs(i);
    	}
    }

    int ans = ind-1,mini=0;
    F(i, 1, ind) {
    	if(cstart[i].second < cstart[mini].second) {
    		mini = i;
    	}
    }

    F(i, 0, ind) {
    	if(i == mini) continue;
    	arr[cstart[i].first] = cstart[mini].first;
    }

    if(cstart[mini].second != 1) {
    	ans++;
    	arr[cstart[mini].first]=cstart[mini].first;
    }

    cout<<ans<<endl;
    F(i, 0, n) {
    	cout<<arr[i]+1<<" ";
    }

    return 0;
}/*

*/