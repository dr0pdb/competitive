#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	cin>>n;

	int arr[n],sum=0;
	int odd=0,even=0;
	F(i, 0, n){
		cin>>arr[i];
		sum+=arr[i];

		if (arr[i] % 2 ==0)
		{
			even++;
		}else{
			odd++;
		}
	}
	if (sum%2==0)
	{
		if (!odd)
		{
			cout<<"Second";
		}else{
			cout<<"First";
		}
	}else{
		cout<<"First";
	}

	return 0;
}