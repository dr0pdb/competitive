#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		int array[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
		}
		int coins =1,sum=array[0];
		for (int i = 1; i < n-1; ++i)
		{
			if (array[i]+sum < array[i+1])
			{
				coins++;
				sum+=array[i];
			}
		}
		coins++;
		cout<<coins<<"\n";
	}
	return 0;
}