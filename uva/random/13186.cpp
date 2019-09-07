/**
    __author__ : srv_twry
**/

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> lll;

const ll MOD = 1000000007;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);

#define FOR(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RFOR(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define ull unsigned long long
#define deb(x )     cerr << #x << " = "<< x << endl;
#define endl    "\n"
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fill(x, y) memset(x, y, sizeof(y))
#define all(x) (x).begin(), (x).end()

inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
/*----------------------------------------------------------------------*/

struct TrieNode
{
	bool end;
	map<char, TrieNode*> children;
};

struct Trie
{
	TrieNode *root;

	Trie() {
		root = new TrieNode();
	}

	void insert(string s) {
		TrieNode *curr = root;
		for(char c : s) {
			if(curr->children.find(c) == curr->children.end()) {
				curr->children[c] = new TrieNode();
			}
			curr = curr->children[c];
		}
		curr -> end = true;
	}
};

string s,p;

ll solve(TrieNode *curr, int idx, int taken) {
	if(idx == p.size()) return taken;

	ll ret = 0;
	if (!taken)
	{
		for(auto itr : curr -> children) {
			ret += solve(itr.second, idx + 1, 1);
		}
	}

	if(curr -> children.find(p[idx]) != curr -> children.end()) {
		ret += solve(curr -> children[p[idx]], idx + 1, taken);
	}
	return ret;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	int n,q,l;
	while(cin>>n>>q>>l) {
		Trie tr;
		FOR(i, 0, n) {
			cin>>s;
			tr.insert(s);
		}
		FOR(i, 0, q) {
			cin>>p;
			cout<<solve(tr.root, 0, 0)<<endl;
		}
	}   

    return 0;
}