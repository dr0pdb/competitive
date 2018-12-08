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
		
	string s;	
	int k;

	bool counter[26]={false};
	cin>>s>>k;

	F(i, 0, s.length()){
		counter[s[i]-'a']=true;
	}
	int ans=0;
	F(i, 0, 26){
		if (counter[i])
		{
			ans++;
		}
	}
	if (k>s.length())
	{
		cout<<"impossible";
	}else{
		if (k<ans)
		{
			cout<<0;
		}else{
			cout<<k-ans;
		}
	}
	return 0;
}