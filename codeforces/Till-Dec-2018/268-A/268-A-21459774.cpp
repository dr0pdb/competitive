#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int count=0;
    int h[n];
    int a[n];
    for(int y=0;y<n;y++){
        cin>>h[y];
        cin>>a[y];
    
    for(int x=0;x<y;x++){
        if(h[y]==a[x]){
            count++;
        }
        if(a[y]==h[x]){
            count++;
        }
    }
    }
    cout<<count<< endl;
    
    
    return 0;
}