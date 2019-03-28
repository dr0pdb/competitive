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
const double eps = 1e-7;
const double PI = acos(-1.0);
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
#define ff first
#define ss second
/*----------------------------------------------------------------------*/

const int N = 55;
int arr[N];
const int MAXX = 2e7+1;
vii m[MAXX];
vii ans,current;
int cnt=0,freq;
set<int> present;

bool cmp(ii a, ii b) {
	return a.first < b.first;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;

    FOR(i, 0, n) {
    	cin>>arr[i];
    	if(i) {
    		arr[i] += arr[i-1];
    	}
    }

    FOR(i, 0, n) {
    	FOR(j, i, n) {
    		int sm = arr[j];
    		if(i) sm -= arr[i-1];
    		sm += (10000000);
    		present.insert(sm);
    		m[sm].push_back({i,j});
    	}
    }

    auto itr = present.begin();
    while(itr != present.end()) {
    	int sm = *itr; ++itr;
    	vii pairs = m[sm];
    	if(!pairs.size()) continue;
    	sort(pairs.begin(), pairs.end(), cmp);

    	// deb(sm);
    	// FOR(i, 0, pairs.size()) {
    	// 	cout<<pairs[i].ff<<" "<<pairs[i].ss<<endl;
    	// }

    	freq=1;
    	current.clear();
    	int sz = pairs.size();
    	int border = pairs[sz-1].first;
    	current.push_back(pairs[sz-1]);
    	RFOR(i, sz-2, 0) {
    		if(pairs[i].second < border) {
    			freq++;
    			current.push_back(pairs[i]);
    			border = pairs[i].first;
    		}
    	}

    	if(freq > cnt) {
    		cnt = freq;
    		ans = current;
    	}
    }

    cout<<cnt<<endl;
    FOR(i, 0, ans.size()) {
    	cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
    }

    return 0;
}