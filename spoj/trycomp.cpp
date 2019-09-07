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
	map<string, int> freq;
	map<char, TrieNode*> children;
	int maxfreq = -1;
	string best;
};

struct Trie
{
	TrieNode *root;

	Trie() {
		root = new TrieNode();
	}

	void insert(string s) {
		TrieNode *curr = root;
		stack<TrieNode*> st;
		for(char c : s) {
			st.push(curr);
			if(curr->children.find(c) == curr->children.end()) {
				curr->children[c] = new TrieNode();
			}
			curr = curr->children[c];
		}
		st.push(curr);
		while(!st.empty()) {
			curr = st.top(); st.pop();
			curr -> freq[s]++;
			int nf = curr -> freq[s];
			if(nf > curr -> maxfreq || (nf == curr -> maxfreq && s < curr -> best)) {
				curr -> maxfreq = nf;
				curr -> best = s;
			}
		}
	}
};

vector<string> arr;
int n,q,freq;
string p, res;

void solve(TrieNode *root) {
	for(int i = 0; i < p.size(); i++) {
		char c = p[i];
		if(root -> children.find(c) == root -> children.end()) {
			res = "-1";
			return;
		}
		root = root -> children[c];
	}

	res = root -> best;
	freq = root -> maxfreq;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n;
    arr.resize(n);
    Trie tr;
    FOR(i, 0, n) {
    	cin>>arr[i];
    	tr.insert(arr[i]);
    }
    cin>>q;
    FOR(i, 0, q) {
    	cin>>p;
    	res = ""; freq = 0;
    	solve(tr.root);
    	cout<<res;
    	if(freq > 0) cout<<" "<<freq;
    	cout<<endl; 
    }
    return 0;
}