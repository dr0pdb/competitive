#include<bits/stdc++.h> 

using namespace std;

int main(){

    int k,x,y;
    double xtemp;
   vector< pair<int,int> > vp;
    while (scanf("%d",&k)==1)
    {
        vp.clear();
        for ( y = k+1; y <= 2*k; y++)
        {
            xtemp=(double)(y*k)/(y-k);
            x=(int)xtemp;

            if (x==xtemp)
            {
                vp.push_back(make_pair(x,y));
            }
        }

        printf("%d\n",vp.size());
        
        for(int i=0;i<vp.size();i++){
            printf("1/%d = 1/%d + 1/%d\n",k,vp[i].first,vp[i].second);
        }
    }

 return 0;  
}

