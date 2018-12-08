#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

	int r,d;
	cin>>r>>d;

	int n;
	cin>>n;

	vector<pair<double, pair<double, double> > >saus;
	double x,y,rt;
	F(i, 0, n){
		cin>>x>>y>>rt;
		saus.push_back(make_pair(rt,make_pair(x,y)));
	}

	int ans=0;
	F(i, 0, n){
		pair<double, pair<double, double> > curr = saus[i];
		double rx=curr.second.first,ry=curr.second.second,rr=curr.first;
		double distance = sqrt((rx*rx)+(ry*ry));
		if ((double)distance-rr>= (double)(r-d) && (double)distance+rr<=(double)r)
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}