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
	
	string a,b;
	cin>>a>>b;

	int n;
	cin>>n;

	cout<<a<<" "<<b<<"\n";
	string x,y;
	F(i, 0, n){
		cin>>x>>y;
		if (x==a)
		{
			a=y;
		}else if (x==b)
		{
			b=y;
		}else if (y==a)
		{
			a=x;
		}else{
			b=x;
		}
		cout<<a<<" "<<b<<"\n";
	}

	return 0;
}