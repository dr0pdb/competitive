#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define mes(i,a) memset(a,i,sizeof(a))
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);
	
	int n,k;
	cin>>n>>k;

	int arr[n];
    bool p=true;
	int left=0,ans=-1;
	F(i, 0, n){
		cin>>arr[i];
		arr[i]+=left;
		left=0;
		if (arr[i]<=8)
		{
			k-=arr[i];
		}else{
			k-=8;
			left+=arr[i]-8;
		}

		if (k<=0 && p)
		{
			ans=i+1;
            p=false;
		}
	}
	cout<<ans;

	return 0;
}