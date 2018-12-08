#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	int slen,tlen;
	cin>>slen>>tlen;

	string s,t;
	cin>>s>>t;

	vector<int>mpos,pos;

	int ans=1000000,count=0;
	F(i, 0, tlen-slen+1){
		count=0;
		pos.clear();
		string sub = t.substr(i,slen);
		F(j, 0, slen){
			if (sub[j] != s[j] )
			{
				count++;
				pos.push_back(j+1);
			}
		}
		if (count < ans)
		{
			ans = count;
			mpos.clear();
			F(j, 0, pos.size()){
				mpos.push_back(pos[j]);
			}
		}
	}

	cout<<ans<<"\n";
	F(i, 0, mpos.size()){
		if (i == 0)
		{
			cout<<mpos[i];
		}else{
			cout<<" "<<mpos[i];
		}
	}
	return 0;
}