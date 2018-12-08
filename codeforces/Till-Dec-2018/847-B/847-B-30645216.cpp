#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define printCase() "Case #" << caseNum << ": "
#define pb push_back
#define mp make_pair
#define INF (int)1e9
#define EPS 1e-9
#define SYNC std::ios::sync_with_stdio(false)
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
 
int main() {
 
    int n; cin >> n;
    vii arr; vi arr2; long int temp;
    FOR0(i,n)
    {
        cin >> temp;
        arr.pb(mp(temp,i));
        arr2.pb(temp);
    }
    sort(arr.begin(),arr.end());
    map<int,int> val;
    FOR0(i,n)
    {
        val[arr[i].ss] = i+1;
    }
    vvi ans;
    ans.resize(n,vi());
    set<long int> ret;
    ret.insert(val[0]);
    int pos = 0;
    ans[pos].pb(arr2[0]);
    map<long int,int> ind;
    ind[val[0]] = pos;
    set<long int>::iterator it;
    FOR(i,1,n)
    {
        it = ret.lower_bound(val[i]);
        if(it == ret.begin())
        {
            pos++;
            ret.insert(val[i]);
            ind[val[i]] = pos;
            ans[pos].pb(arr2[i]);
        }
        else
        {
            it--;
            ans[ind[*it]].pb(arr2[i]);
            ind[val[i]] = ind[*it];
            ret.erase(it);
            ret.insert(val[i]);
        }
    }
    FOR0(i,pos+1)
    {
        FOR0(j,ans[i].size())
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}