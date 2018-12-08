#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int x=0; x<n;x++){
        string a;
        cin>> a;
        if(a.length()>10){
            cout<< a.at(0);
            cout<< a.length()-2;
            cout<< a.at(a.length()-1) << endl;
        }
        else{
            cout << a << endl;
        }
    }
    return 0;
}