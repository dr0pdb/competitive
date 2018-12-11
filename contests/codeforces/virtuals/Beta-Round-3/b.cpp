#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define SIEVELIM 10000000+10
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
#define ull unsigned long long
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
inline int nextint(){ int temporary; scanf("%d",&temporary); return temporary; }
inline ll nextll(){ ll temporary; scanf("%lld",&temporary); return temporary; }
inline double nextdouble(){double temporary; scanf("%lf",&temporary); return temporary;}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
ll leftChild(ll p ){return p<<1;}
ll rightChild(ll p ){return (p<<1)+1;}
inline ll mid(ll l, ll r){ return (l+r)/2;}
const ll MOD = 1000000007;
const ll INF = LONG_LONG_MAX;
const double eps = 1e-7;
const double PI = acos(-1.0);
#define deb(x )     cerr << #x << " here "<< x; 
#define endl    "\n"
#define pb push_back
#define mp make_pair
#define all(cc) (cc).begin(),(cc).end()

inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }

template<typename T > void modulize(T & a, const T & b) { if (a >= b) { a %= b; } }
ll mulmod(ll a, ll b, ll m) { ll q = (ll)(((ld)a*(ld)b) / (ld)m); ll r = a*b - q*m; if (r>m)r %= m; if (r<0)r += m; return r; }
template <typename T, typename S>T expo(T e, S n) { T x = 1, p = e; while (n) { if (n & 1)x = x*p; p = p*p; n >>= 1; }return x; }
template <typename T>T power(T e, T n, T & m) { T x = 1, p = e; while (n) { if (n & 1)x = mod(x*p, m); p = mod(p*p, m); n >>= 1; }return x; }
template <typename T>T powerL(T e, T n, T & m) { T x = 1, p = e; while (n) { if (n & 1)x = mulmod(x, p, m); p = mulmod(p, p, m); n >>= 1; }return x; }
template <typename T> T InverseEuler(T a, T & m) { return (a == 1 ? 1 : power(a, m - 2, m)); }

inline int two(int n) { return 1 << n; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
/*----------------------------------------------------------------------*/

const int maxN = 100005;

int size[maxN], profit[maxN];

struct compareByProfit
{
    bool operator() (int a, int b)
    {
        return profit[a] > profit[b];
    }
};

int main()
{
    int N, maxSize;
    scanf ("%i %i", &N, &maxSize);

    vector <int> first, second;

    for (int i = 0; i < N; i++)
    {
        scanf ("%i %i", &size[i], &profit[i]);
        if (size[i] == 1)
            first.push_back (i);
        else
            second.push_back (i);
    }

    sort (first.begin(), first.end(), compareByProfit());
    sort (second.begin(), second.end(), compareByProfit());

    int numFirstTaken = 0, numSecondTaken = 0;
    int freeSpace = maxSize, answer = 0;

    while (numFirstTaken < (int)first.size() && freeSpace >= size[first[numFirstTaken]])
    {
        answer += profit[first[numFirstTaken]];
        freeSpace -= size[first[numFirstTaken++]];
    }

    int bestAnswer = 0, bestFirst = 0, bestSecond = 0;

    while (true)
    {
        // Take as much seconds as possible

        while (numSecondTaken < (int)second.size() && freeSpace >= size[second[numSecondTaken]])
        {
            answer += profit[second[numSecondTaken]];
            freeSpace -= size[second[numSecondTaken++]];
        }

        // Rate current way

        if (answer > bestAnswer)
        {
            bestAnswer = answer;
            bestFirst = numFirstTaken;
            bestSecond = numSecondTaken;
        }

        // Remove one first

        if (numFirstTaken == 0) break;
        numFirstTaken--;
        answer -= profit[first[numFirstTaken]];
        freeSpace += size[first[numFirstTaken]];
    }

    printf ("%i\n", bestAnswer);
    for (int i = 0; i < bestFirst; i++) printf ("%i ", first[i] + 1);
    for (int i = 0; i < bestSecond; i++) printf ("%i ", second[i] + 1);
    printf ("\n");

    return 0;
}/*
    
*/
 