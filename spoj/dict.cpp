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

#define maxx 500005
#define intt int

intt trie[maxx][26]={0}, finish[maxx]={0};
intt nxt = 1;
void insert (string &s){
    intt node = 0;
    for (intt i = 0; s[i] != '\0'; i++) {
        if(trie[node][s[i] - 'a'] == 0) {
            node = trie[node][s[i] - 'a'] = nxt;
            nxt++;
        } else {
            node = trie[node][s[i] - 'a'];
        }
    }
    finish[nxt - 1] = 1;
}

bool printAll(intt idx, intt sidx, string &prefix, string &sofar) {
	if(sidx < prefix.size()) {
		char c = prefix[sidx];
		if(trie[idx][c-'a'] == 0) {
			return false;
		} else {
			sofar += c;
			return printAll(trie[idx][c-'a'], sidx+1, prefix, sofar);
		}
	}

	bool ret = false;
	if (finish[idx] && sidx > prefix.size())
	{
		cout<<sofar<<endl;
		ret = true;
	}

	FOR(i, 0, 26) {
		if(trie[idx][i]) {
			sofar += (char) (i + 'a');
			ret |= printAll(trie[idx][i], sidx+1, prefix, sofar);
			sofar.pop_back();
		}
	}

	return ret;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,m;
    cin>>n;

    string s, sofar;
    FOR(i, 0, n) {
    	cin>>s;
    	insert(s);
    }
    cin>>m;
    FOR(i, 1, m+1) {
    	cout<<"Case #"<<i<<":\n";
    	cin>>s;
    	sofar="";
    	if(!printAll(0, 0, s, sofar)) cout<<"No match.\n";
    }

    return 0;
}