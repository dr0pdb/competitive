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

const int N = 30;
vi g[N];
int indeg[N], outdeg[N];
bool pres[N],visited[N];
int n;

void dfs(int curr) {
    visited[curr] = true;
    for(int nxt : g[curr]) {
        if(!visited[nxt]) {
            dfs(nxt);
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t,u,v; cin>>t; string s;
    while(t--) {
        cin>>n;
        memset(indeg, 0, sizeof(indeg));  memset(outdeg, 0, sizeof(outdeg)); memset(pres, false, sizeof(pres));
        FOR(i, 0, 30) g[i].clear(); 
        FOR(i, 0, n) {
            cin>>s;
            u = s[0]-'a'; v = s.back()-'a';
            g[u].push_back(v);
            outdeg[u]++; indeg[v]++;
            pres[u] = pres[v] = true;
        }
        bool impos = false;
        int in = -1, out = -1;
        FOR(i, 0, N) {
            if(indeg[i] == outdeg[i]) continue;
            if(indeg[i] == outdeg[i] + 1) {
                if(in == -1) in = i;
                else impos = true;
            } else if(outdeg[i] == indeg[i] + 1) {
                if(out == -1) out = i;
                else impos = true;
            } else {
                impos = true;
            }
        }
        if(impos) {
            cout<<"The door cannot be opened.\n";
            continue;
        }
        if(out == -1) out = 0; // in case of euler cycle, start from anywhere.
        memset(visited, false, sizeof(visited));
        dfs(out); bool noans = false;
        FOR(i, 0, N) {
            if(pres[i] != visited[i]) {
                noans = true;
                break;
            }
        }
        if(noans) {
            cout<<"The door cannot be opened.\n";
        } else {
            cout<<"Ordering is possible.\n";
        }
    }

    return 0;
}