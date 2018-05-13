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

vector<vector<int> > positions(256);

int main(){
	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

	string s;
	cin>>s;

	F(i, 0, s.length()){
		positions[s[i]].push_back(i);
	}
	int q;
	cin>>q;

	while(q--){
		string qs;
		cin>>qs;

		int index=-1,first;
		bool ans = true;
		F(i, 0, qs.length()){
			char c = qs[i];
			auto itr = upper_bound(positions[c].begin(),positions[c].end(),index);
			if (itr == positions[c].end())
			{
				cout<<"Not matched\n";
				ans = false;
				break;
			}
			if (i==0)
			{
				first = *itr;
			}
			index = *itr;
		}
		if (ans)
		{
			cout<<"Matched "<<first<<" "<<index<<"\n";
		}
		
	}

	return 0;
}