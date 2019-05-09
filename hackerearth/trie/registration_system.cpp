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

#define maxx 1000005
#define intt int

intt trie[maxx][50], finish[maxx];
intt nxt = 1;
map<char, int> mval;

void insert (string s){
    intt node = 0;
    for (intt i = 0; i < s.size(); i++) {
        if(trie[node][mval[s[i]]] == 0) {
            node = trie[node][mval[s[i]]] = nxt;
            nxt++;
        } else {
            node = trie[node][mval[s[i]]];
        }
    }
    finish[node] = 1;
    finish[nxt - 1] = 1;
}

intt find (string s) {
    intt idx = 0;
    for (intt i = 0; i < s.size(); i++)
        if (trie[idx][mval[s[i]]] == 0)
            return 0;
        else
            idx = trie[idx][mval[s[i]]];
    return finish[idx];
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n; cin>>n;
    memset(finish, 0, sizeof(finish));
    memset(trie, 0, sizeof(trie));

    int cnt = 0;
    for (char i = 'a'; i <= 'z'; ++i)
    {
		mval[i] = cnt++;
    }
    FOR(i, 0, 10) {
    	mval[i + '0'] = cnt++;
    }

    string s;
    while(n--) {
    	cin>>s;
    	if(find(s)) {
    		int dig = 0;
    		while(find(s + to_string(dig))) dig++;
    		s += to_string(dig);
    	}
    	cout<<s<<endl;
    	insert(s);
    }

    return 0;
}