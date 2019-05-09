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

#define maxx 200001
#define intt int

intt trie[maxx][130]; set<int> cnt[maxx];
intt nxt = 1;
void insert (string s, int string_num){
    intt node = 0;
    for (intt i = 0; i < s.size(); i++) {
        if(trie[node][s[i]] == 0) {
            node = trie[node][s[i]] = nxt;
            cnt[node].insert(string_num);
            nxt++;
        } else {
            node = trie[node][s[i]];
           	cnt[node].insert(string_num);
        }
    }
}

intt find (string s) {
    intt idx = 0;
    for (intt i = 0; i < s.size(); i++)
        if (trie[idx][s[i]] == 0)
            return 0;
        else
            idx = trie[idx][s[i]];
    return cnt[idx].size();
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,q;
    cin>>n>>q;

    string s, tmp;
    FOR(i, 0, n) {
    	cin>>s;
    	reverse(s.begin(), s.end());
    	tmp.clear();
    	FOR(j, 0, s.size()) {
    		tmp.push_back(s[j]);
    		reverse(tmp.begin(), tmp.end());
    		insert(tmp, i);
    		reverse(tmp.begin(), tmp.end());
    	}
    }

    FOR(i, 0, q) {
    	cin>>s;
    	cout<<find(s)<<endl;
    }

    return 0;
}