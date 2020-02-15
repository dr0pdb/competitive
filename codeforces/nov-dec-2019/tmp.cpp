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

bool cmp(pair<int,int>a, pair<int,int> b)
{
    if(a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int main()
{
    int n, threshold;
    cin >> n;
    int b[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }
    cin >> threshold;
    vector<int>result;
    vector<pair<int,int>> a;
    int minm = INT_MAX, index = -1;

    for (int i = 0; i < n; ++i)
    {
        a.push_back(make_pair(b[i],i));
        if(minm > b[i]) 
        {
            minm = b[i];
            index =  i;
        }
    }
    sort(a.begin(), a.end(), cmp);

    int length = threshold/minm;
    int sum = length * minm;
    
    for(int i = 0; i < length; i++) {
        int max_kick = threshold - (length - i - 1)*minm;

        int idx = INT_MAX, kick_value;
        for(int j = 0; j < n; j++) {
            if(a[j].first <= max_kick) {
                if(a[j].second < idx) {
                    idx = a[j].second;
                    kick_value = a[j].first;
                }
            } else break;
        }

        threshold -= kick_value;
        result.push_back(idx + 1); // answer expects 1 based indexing.
    }

    return 0;
}