#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;

int main(){
	std::ios::sync_with_stdio(false);
	
	int b,s,casen=1;

	int bt[10010],sp[10010];
	bool used[10010][2];


	while(cin>>b>>s && b && s ){
		
		F(i, 0, b){
			cin>>bt[i];
		}
		F(i, 0, s){
			cin>>sp[i];
		}

		//every batchelor will get married
		if (b <= s)
		{
			cout<<"Case "<<casen++<<": 0\n";
			continue;
		}

		memset(used,false,sizeof(used));
		int ans = 1000000;
		F(i, 0, b){
			ans = min(ans,bt[i]);
		}

		cout<<"Case "<<casen++<<": "<<b-s<<" "<<ans<<"\n";

	}

	return 0;
}

