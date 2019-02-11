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

	int g[n],f[n];
	int counter[2][5]={0};
	F(i, 0, n){
		cin>>g[i];
		counter[0][g[i]-1]++;
	}
	F(i, 0, n){
		cin>>f[i];
		counter[1][f[i]-1]++;
	}

	int ans=0;
	int changes[5]={0};
	int tchange=0,a;

	F(i, 0, 5){
		changes[i]=counter[0][i]-counter[1][i];
		if (abs(changes[i])%2)
		{
			cout<<-1;
			return 0;
		}
		tchange+=counter[0][i]-counter[1][i];
		if (counter[0][i]-counter[1][i]>0)
		{
			a+=counter[0][i]-counter[1][i];
		}
		
	}

	if (tchange)
	{
		cout<<-1;
	}else{
		cout<<a/2<<endl;
	}

	return 0;
}