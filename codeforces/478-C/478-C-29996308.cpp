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

	ll balls[3],ans=0;
	F(i, 0, 3){
		cin>>balls[i];
	}
	sort(balls,balls+3);
	
	if (2*(balls[0] + balls[1]) <= balls[2])
	{
		ans=balls[0]+balls[1];
	}else{
		ans = balls[0]+balls[1]+balls[2];
		ans/=3;
	}

	cout<<ans;

	return 0;
}