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
	set<int> idx;
	set<int> terms;
	map<char, TrieNode*> children;
};

struct Trie
{
	TrieNode *root;

	Trie() {
		root = new TrieNode();
	}

	void insert(string s, int j) {
		TrieNode *curr = root;
		for(int i = 0; i < s.size(); i++) {
			curr -> terms.insert(j);
			if(curr->children.find(s[i]) == curr->children.end()) {
				curr -> children[s[i]] = new TrieNode();
			}
			curr = curr -> children[s[i]];
		}
		curr -> terms.insert(j);
		curr -> idx.insert(j);
	}

	void del(string s, int j) {
		TrieNode *curr = root;
		for(int i = 0; i < s.size(); i++) {
			curr -> terms.erase(curr -> terms.find(j));
			curr = curr -> children[s[i]];
		}
		curr -> terms.erase(curr -> terms.find(j));
		curr -> idx.erase(curr -> idx.find(j));
	}
};

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    

    return 0;
}