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

	int k;
	string n;

	cin>>k>>n;
	int sumd=0;
	F(i,0,n.length()){
		sumd+=n[i]-'0';
	}
	if (sumd >= k)
	{
		cout<<0;
	}else{
		int diff=k-sumd;
		sort(n.begin(),n.end());
		int ans=0;
		for (int i = 0; i < n.length() && diff; ++i)
		{
			diff-=9-(n[i]-'0');
			ans++;

			if (diff<=0)
			{
				diff=0;
			}
		}
		cout<<ans;
	}
	return 0;
}