#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 1000000000
#define MOD 1000000000+7
#define EPS 1e-7
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
		
	int n;
	cin>>n;

	int x,y;
	while(n--){
		cin>>x>>y;
		if (x==y)
		{
			if (x%2)
			{
				cout<<2*x-1;
			}else{
				cout<<2*x;
			}
		}else if (x==(y+2))
		{
			if (y%2==0)
			{
				cout<<2*y+2;
			}else{
				cout<<2*y+1;
			}
		}else{
			cout<<"No Number";
		}
		cout<<"\n";
	}
	return 0;
}