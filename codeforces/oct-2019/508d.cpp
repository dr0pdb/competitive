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
inline void print_case(int tn) {cout<<"Case #"<<tn<<": ";}

template<typename T>
using maxpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using minpq = priority_queue<T>;
/*----------------------------------------------------------------------*/

const int N = 4000;
string s;
unordered_map<string, int> wordtoidx;
vector<string> idxtoword;
vector<int> indeg, outdeg;
vi g[N]; int src;
bool visited[N]; int vcount = 0;

void dfs(int curr) {
    visited[curr] = true;
    vcount++;

    for(int nxt : g[curr]) {
        if(!visited[nxt]) {
            dfs(nxt);
        }
    }
}

bool sol_exists() {
    src = -1; int dest = -1;
    FOR(i, 0, idxtoword.size()) {
        if(indeg[i] == outdeg[i]) continue;
        if(indeg[i] == outdeg[i] + 1) {
            if(dest == -1) dest = i;
            else return false;
        }
        else if(outdeg[i] == indeg[i] + 1) {
            if(src == -1) src = i;
            else return false;
        }
        else return false;
    }
    if(src == -1) src = 0;
    memset(visited, false, sizeof(visited));
    dfs(src);
    if(vcount != idxtoword.size()) return false;
    return true;
}

vi res;
void find_euler(int curr) {
    while(!g[curr].empty()) {
        int nxt = g[curr].back();
        g[curr].pop_back();
        find_euler(nxt);
    }
    res.push_back(curr);
}
 
int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n; cin>>n;
    FOR(i, 0, n) {
        cin>>s;
        string s1 = s.substr(0, 2); string s2 = s.substr(1, 2);
        int u,v;
        if(wordtoidx.find(s1) != wordtoidx.end()) {
            u = wordtoidx[s1];
        } else {
            u = idxtoword.size();
            idxtoword.push_back(s1);
            indeg.push_back(0); outdeg.push_back(0);
            wordtoidx[s1] = u;
        }
        if(wordtoidx.find(s2) != wordtoidx.end()) {
            v = wordtoidx[s2];
        } else {
            v = idxtoword.size();
            idxtoword.push_back(s2);
            indeg.push_back(0); outdeg.push_back(0);
            wordtoidx[s2] = v;
        }
        g[u].push_back(v);
        outdeg[u]++; indeg[v]++;
    }
    if(!sol_exists()) {
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    find_euler(src);
    reverse(all(res));
    FOR(i, 0, res.size()) {
        s = idxtoword[res[i]];
        if(i == 0) {
            cout<<s;
        } else {
            cout<<s.substr(1);
        }
    }
    return 0;
}