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
	std::ios::sync_with_stdio(false);
	
	int n,k;
	cin>>n>>k;

	string s;
	cin>>s;

	int gpos=-1,tpos=-1;
	bool pos=false;

	F(i, 0, s.length()){
		
		if (s[i]=='G')
		{
			gpos=i;
		}else if(s[i]=='T'){
			tpos=i;
		}
	}

	for (int i = min(gpos, tpos); i < s.length(); i+=k)
	{
		if (i==max(gpos,tpos))
		{
			pos = true;
			break;
		}else if(s[i]=='#'){
			pos = false;
            break;
		}

	}

	if (pos)
	{
		cout<<"YES";
	}else{
		cout<<"NO";
	}

	return 0;
}