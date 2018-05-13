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
	//std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	
	int t,d,v,u;
	cin>>t;

	F(tn, 1, t+1){
		cin>>d>>v>>u;
		if (v>=u || !u || !v)
		{
			printf("Case %d: can't determine\n",tn);
		}else{
			double coste = (double)v/(double)u;
			double sinte = sqrt(1.00-(coste*coste));
			double ans = (d/(double)u)*((1.0/sinte)-1.0);
			printf("Case %d: %.3lf\n",tn,ans);
			//cout<<fixed<<setprecision(3)<<ans<<"\n";
		}
		
	}

	return 0;
}