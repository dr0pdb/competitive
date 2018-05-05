#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 1000000000
#define EPS 1e-7
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;
 
using namespace std;
 
const int me = 100025;
const int mod = 100000000;
 
void add(int &a, int b){
    a += b;
    if(a >= mod)
        a -= mod;
}
 
int n;
int dp[me];
pair<int, int> a[me];
 
bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}
 
int main(int argc, const char * argv[]) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    while(scanf("%d", &n)){
        if(n == -1)
            break;
        for(int i = 1; i <= n; i ++)
            scanf("%d%d", &a[i].first, &a[i].second);
        sort(a + 1, a + n + 1, cmp);
        dp[0] = 1;
        for(int i = 1; i <= n; i ++){
            dp[i] = dp[i - 1];
            auto next_pos = upper_bound(a, a + n + 1, make_pair(0, a[i].first), cmp) - a - 1;
            add(dp[i], dp[next_pos]);
        }
        add(dp[n], mod - 1);
        cout << setfill('0') << setw(8) << dp[n] << endl;
    }
 
    return 0;
}