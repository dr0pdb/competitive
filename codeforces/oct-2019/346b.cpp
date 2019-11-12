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
#define bitcount(x) __builtin_popcount(x)
#define cps CLOCKS_PER_SEC

inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void print_case(int tn) {cout<<"Case #"<<tn<<": ";}

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using maxpq = priority_queue<T>;
/*----------------------------------------------------------------------*/

const int N = 105;
string s1,s2,v;
int dp[N][N][N];
iii par[N][N][N];
vector<vi> autm;

vi prefix_function(string s) {
    int n = s.size();
    vi p(s.size());
    FOR(i, 1, n) {
        int j = p[i - 1];
        while(j > 0 && s[i] != s[j]) j = p[j - 1];
        if(s[i] == s[j]) j++;
        p[i] = j;
    }
    return p;
}

// aut[i][c] stores the next value of prefix function if the text t contains
// character c after matching the first i positions with the string s.
void compute_automaton(string s, vector<vector<int>>& aut) {
    s += '#';
    int n = s.size();
    vector<int> pi = prefix_function(s);
    aut.assign(n, vector<int>(26));
    for (int i = 0; i < n; i++) {
        for (int c = 0; c < 26; c++) {
            char x = 'A' + c;
            if (i > 0 && x != s[i])
                aut[i][c] = aut[pi[i-1]][c];
            else
                aut[i][c] = i + (x == s[i]);
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();
    cin>>s1>>s2>>v;
    compute_automaton(v, autm);
    iii last = {-1, {-1, -1}};
    
    FOR(i, 0, s1.size() + 1) {
        FOR(j, 0, s2.size() + 1) {
            FOR(k, 0, v.size() + 1) {
                dp[i][j][k] = 0;
                par[i][j][k] = last;
            }
        }
    }

    int ans = 0; iii start = last;

    FOR(i, 0, s1.size()) {
        FOR(j, 0, s2.size()) {
            FOR(k, 0, v.size()) {
                bool eq = (s1[i] == s2[j]);
                int nxt = autm[k][s1[i]-'A'];

                if(eq && nxt < v.size()) {
                    if(dp[i+1][j+1][nxt] < dp[i][j][k] + 1) {
                        dp[i+1][j+1][nxt] = dp[i][j][k] + 1;
                        par[i+1][j+1][nxt] = {i, {j, k}};
                    }
                }

                if(dp[i+1][j][k] < dp[i][j][k]) {
                    dp[i+1][j][k] = dp[i][j][k];
                    par[i+1][j][k] = par[i][j][k];
                }

                if(dp[i][j+1][k] < dp[i][j][k]) {
                    dp[i][j+1][k] = dp[i][j][k];
                    par[i][j+1][k] = par[i][j][k];
                }

                // if(ans < dp[i][j][k]) {
                //     ans = dp[i][j][k];
                //     start = {i, {j, k}};
                // }
            }
        }
    }
    
    FOR(i, 0, s1.size() + 1) {
        FOR(j, 0, s2.size() + 1) {
            FOR(k, 0, v.size()) {
                if(dp[i][j][k] > ans) {
                    ans = dp[i][j][k];
                    start = par[i][j][k];
                }
            }
        }
    }

    string res;
    do {
        if(start == last) break;
        res.push_back(s1[start.ff]);
        start = par[start.ff][start.ss.ff][start.ss.ss];
    } while(true);

    reverse(all(res));
    if(res.empty()) cout<<0;
    else cout<<res;
    
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}