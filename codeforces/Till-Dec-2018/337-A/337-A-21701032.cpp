#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int m;
    int x[1000];
    cin>>n>>m;
    for(int y=0; y<m; y++){
        cin>>x[y];
    }

    sort(x,x+m);
    int least= x[n-1]-x[0];
    for(int z=1; z<=m-n;z++){
        if(x[n+z-1]-x[z]< least){
            least=x[n+z-1]- x[z];
        }
    }
    cout <<least<<endl;


    return 0;
}