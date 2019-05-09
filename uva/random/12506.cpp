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

#define maxx 1000001
#define intt int

intt trie[maxx][26], finish[maxx], cnt[maxx];
intt nxt = 1;
void insert (string s){
    intt node = 0;
    for (intt i = 0; s[i] != '\0'; i++) {
        if(trie[node][s[i] - 'a'] == 0) {
            node = trie[node][s[i] - 'a'] = nxt;
            cnt[node]++;
            nxt++;
        } else {
            node = trie[node][s[i] - 'a'];
        	cnt[node]++;
        }
    }
    // cnt[node]++;
    finish[node]=1;
    finish[nxt - 1] = 1;
}

intt ans = 0;
void dfs(intt idx, int depth) {
	if(idx && cnt[idx] == 0) return;
	else if(cnt[idx] == 1) {
		ans += depth;
		return;
	}
	FOR(i, 0, 26) {
		if(trie[idx][i])
			dfs(trie[idx][i], 1 + depth);
	}
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t,n;
    string s;
    cin>>t;

    while(t--) {
    	memset(trie, 0, sizeof(trie)); memset(cnt, 0, sizeof(cnt));
    	memset(finish, 0, sizeof(finish)); nxt = 1; ans = 0;
    	cin>>n;
    	FOR(i, 0, n) {
    		cin>>s;
    		insert(s);
    	}
    	dfs(0, 0);
    	cout<<ans<<endl;
    }

    return 0;
}