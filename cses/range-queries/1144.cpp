#include<iostream>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

#define FOR(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RFOR(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
/*----------------------------------------------------------------------*/

const int N = 2e5+5;
int arr[N],n,q;
indexed_set s;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    cin>>n>>q;
    FOR(i, 0, n) {
        cin>>arr[i];
        s.insert(arr[i]);
    }

    char c; int x, y;
    while(q--) {
        cin>>c>>x>>y;
        if(c == '!') {
            x--;
            s.erase(s.find_by_order(s.order_of_key(arr[x])));
            arr[x] = y;
            s.insert(arr[x]); 
        } else {
            cout<<s.order_of_key(y + 1) - s.order_of_key(x)<<endl;
        }
    }
   
    return 0;
}