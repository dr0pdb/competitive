#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 1000000000
#define EPS 1e-7
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

bool check(char a ,char b){
	int first = a-'0';
	if (!first)
	{
		return false;
	}
	int second = b - '0';
	int value = 10*first + second;
	if (value>=1 && value<=26)
	{
		return true;
	}
	return false;
}

int main(){
	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

	string s;
	while(cin>>s){
		bool noAns=false;
		if (s=="0")
		{
			break;
		}
		int n=s.length();
		ll dp[n+1]={0};
		dp[0]=1;
		dp[1]=1;
		F(i, 2, n+1){
			if (s[i-1]!='0')
			{
				dp[i] = dp[i-1];	
			}
			if (check(s[i-2],s[i-1]))
			{
				dp[i]+=dp[i-2];
			}
			if (check(s[i-2],s[i-1])==false && s[i-1]=='0')
			{
				cout<<"0\n";
				noAns=true;
				break;
			}
			
		}
		if (noAns)
		{
			continue;
		}
		cout<<dp[n]<<"\n";
	}
	
	return 0;
}