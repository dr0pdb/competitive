#include<bits/stdc++.h>

using namespace std;

multiset< int > urn;

int main()
{
    int n, m, a;
    
    while ( scanf("%d",&n)==1 && n )
    {
        long long ans = 0LL;
        urn.clear();
        for (int i=0; i<n; i++)
        {
            scanf("%d",&m);
            for (int j=0; j<m; j++)
            {
                scanf("%d",&a);
                urn.insert( a );
            }
            ans += *urn.rbegin() - *urn.begin();
            urn.erase( urn.begin() );
            
            urn.erase( --urn.end());
        }
        printf("%lld\n",ans);
    }
    
    return 0;
}

