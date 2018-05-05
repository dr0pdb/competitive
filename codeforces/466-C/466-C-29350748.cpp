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
	
	int n;
	cin>>n;

	ll s=0;

	int arr[n];
	F(i, 0, n){
		cin>>arr[i];
		s+=arr[i];
	}	
	
	if (s%3)
	{
		cout<<"0";
	}else{
		s/=3;
		ll ss=0;
		int cnt[n]={0};
		RF(i, n-1, 0){
			ss+=arr[i];
			if (ss==s)
			{
				cnt[i]=1;	
			}
		}

		RF(i, n-2, 0){
			cnt[i]+=cnt[i+1];
		}

		ll ans=0;
		ss=0;
		F(i, 0, n-2){
			ss+=arr[i];
			if (ss==s)
			{
				ans+=cnt[i+2];
			}
		}	
		cout<<ans;
	}

	return 0;
}