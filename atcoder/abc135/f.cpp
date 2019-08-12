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

#define MAX_N 500010

string s,t;
int prefix[MAX_N], n, m; // n = size of text, m = size of pattern.

void kmpPreprocess() {
	int i = 0, j = -1; prefix[0] = -1;

	while (i < m) {
		while (j >= 0 && t[i] != t[j]) j = prefix[j];
		i++; j++;
		prefix[i] = j;
	} 
}

set<int> kmpSearch(int n2) {
	int i = 0, j = 0;
	set<int> matches;

	while (i < n) {
		while (j >= 0 && s[i] != t[j]) j = prefix[j];
		i++; j++;
		if (j == m) {
			matches.insert((i - j)%n2);
			// printf("P is found at index %d in T\n", i - j);
			j = prefix[j]; // prepare j for the next possible match
		}
	}

	return matches;
}

vi nodes;
bool visited[MAX_N], cyclic;
vi g[MAX_N];
int dist[MAX_N];

void dfs(int curr, vi &ts, set<int> &pars) {
	if (cyclic)
	{
		return;
	}
	pars.insert(curr);		
	visited[curr] = true;
	for(auto nxt: g[curr]) {
		if (!visited[nxt])
		{
			dfs(nxt, ts, pars);
		} else if (pars.find(nxt) != pars.end())
		{
			cyclic = true;
			return;
		}
	}
	pars.erase(curr);
	ts.push_back(curr);
}

void dfs2(int curr) {
	visited[curr] = true;
	for(auto nxt : g[curr]) {
		if (!visited[nxt])
		{
			dist[nxt] = dist[curr] + 1;
			dfs2(nxt);
		}
	}
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>s>>t; int n2 = s.size();
    while(s.size() < t.size()) {
    	s += s;	
    }
    s += s;
    n = s.size(); m = t.size();
    kmpPreprocess();
    set<int> matches = kmpSearch(n2);
    for(auto pos : matches) {
    	nodes.push_back(pos);
    	int nxt = (pos + m)%n2;
    	if(matches.find(nxt) != matches.end()) {
    		g[pos].push_back(nxt);
    	}
    }
    vi ts; memset(visited, false, sizeof(visited)); set<int> pars;
    cyclic = false;
    FOR(i, 0, nodes.size()) {
    	if (cyclic)
    	{
    		break;
    	}
    	if (!visited[nodes[i]])
    	{
    		dfs(nodes[i], ts, pars);
    	}
    }
    if(cyclic) {
    	cout<<-1;
    	return 0;
    }
    reverse(ts.begin(), ts.end());
    memset(dist, 0, sizeof(dist)); memset(visited, false, sizeof(visited));
    for(auto curr : ts) {
    	if(!visited[curr]) {
			dist[curr] = 1;
			dfs2(curr);	
    	}
    }
    int ans = *max_element(dist, dist+n2);
    cout<<ans;

    return 0;
}