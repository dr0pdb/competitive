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
#define verify(x) if(x >= MOD) x -= MOD;

inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void print_case(int tn) {cout<<"Case #"<<tn<<": ";}

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using maxpq = priority_queue<T>;
/*----------------------------------------------------------------------*/

int l;
vector<string> arr;
vi dom;
ll freq[2][26], dist[2][26]; // freq and num of strings containing a character.
ll k[2];

bool isVowel(char ch){
	return ch == 'a' || ch == 'e' || ch == 'o' || ch == 'u' || ch == 'i';
}

// should be sufficient to check all size 2 substrings.
int find_domain(string &s) {
    int vows = 0, cons = 0; bool good = true;
    FOR(i, 0, 2) {
        if(isVowel(s[i])) vows++;
        else cons++;
    }
    good &= (vows >= cons);
    FOR(i, 2, s.size()) {
        if(isVowel(s[i])) vows++;
        else cons++;

        good &= (vows >= cons);
        if(!good) break;

        if(isVowel(s[i-2])) vows--;
        else cons--;
    }
    return good;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    int t; cin>>t;
    while(t--) {
        cin>>l; arr.clear(); arr.resize(l); dom.clear(); dom.resize(l); k[0] = k[1] = 0;
        memset(freq, 0, sizeof(freq)); memset(dist, 0, sizeof(dist));
        FOR(i, 0, l) cin>>arr[i];
        FOR(i, 0, l) {
            dom[i] = find_domain(arr[i]); // deb(dom[i]);
            k[dom[i]]++;
            bool pres[26] = {false};
            for(char c : arr[i]) {
                freq[dom[i]][c - 'a']++;
                if(!pres[c - 'a']) {
                    pres[c - 'a'] = true;
                    dist[dom[i]][c - 'a']++;
                }
            }
        }
        long double prod0 = 0, prod1 = 0;
        FOR(i, 0, 26) {
            // cerr<<i<<" "<<dist[0][i]<<" "<<dist[1][i]<<" "<<freq[0][i]<<" "<<freq[1][i]<<endl;
            if(dist[0][i]) {
                prod0 += (log((ld)dist[0][i]) - k[0] * log((ld)freq[0][i]));
            }
            if(dist[1][i]) {
                prod1 += (log((ld)dist[1][i]) - k[1] * log((ld)freq[1][i]));
            }
        }
        // deb(prod1); deb(prod0);
        long double res = exp(prod1 - prod0);
        if(res > (1e7)) {
            cout<<"Infinity\n";
        } else {
            coud(res, 10); cout<<endl;
        }
    }
   
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}