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

	int n,k;
	cin>>n>>k;

	string s;
	cin>>s;

	int counter[26]={0};
	bool ans = true;
	F(i, 0, s.length()){
		counter[s[i]-'a']++;
		if (counter[s[i]-'a']>k)
		{
			ans = false;
			break;
		}
	}
	if (ans)
	{
		cout<<"YES";
	}else{
		cout<<"NO";
	}

	return 0;
}