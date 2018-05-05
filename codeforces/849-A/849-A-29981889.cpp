#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

	int n;
	cin>>n;
	int arr[n];
	F(i, 0, n){
		cin>>arr[i];
	}
	if (n%2==0)
	{
		cout<<"No";
		return 0;	
	}

	if (arr[0]%2 && arr[n-1]%2)
	{
		cout<<"Yes";
	}else{
		cout<<"No";
	}
	return 0;
}