#include <iostream>
#include<string>
#include <locale>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    int sum=0;
    int b=0;
    int count=0;
    cin>> n;
    int x[105];
    for(int y=0; y<n;y++){
        cin>> x[y];
        sum+=x[y];
    }
    sort(x,x+n);
    for(int q=n-1;q>=0;q--){
            b+=x[q];
            count++;
            if(b>sum/2){
                break;
            }

    }
    cout<< count;
        return 0;
}