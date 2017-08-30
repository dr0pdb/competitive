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

	bitset<26> state;
	int n,m;
	vector<vector<int> > v(26);
	
	while(cin>>n>>m){
		cin.ignore();
		fill(v.begin(),v.end(),vi());
		state.reset();

		char c,c2;
		F(i, 0, 3){
			cin>>c;
			state.set(c-'A');
		}

		F(i, 0, m){
			cin>>c>>c2;
			v[c-'A'].push_back(c2-'A');
			v[c2-'A'].push_back(c-'A');
		}

		int years=0;
		bool poss = true;
		while(state.count()<n){

			vi wokeUp;
			F(i, 0, 26){
				if (state[i])
				{
					continue;
				}

				int awakeNeighbours=0;
				F(j, 0, v[i].size()){
					vi curr = v[i];
					if (state[curr[j]])
					{
						awakeNeighbours++;
					}
				}
				if (awakeNeighbours>=3)
				{
					wokeUp.push_back(i);
				}
			}

			if (wokeUp.empty())
			{
				cout<<"THIS BRAIN NEVER WAKES UP\n";
				poss = false;
				break;
			}
			years++;
			F(j, 0, wokeUp.size()){
				state.set(wokeUp[j]);
			}
		}
		if (poss)
		{
			cout<<"WAKE UP IN, "<<years<<", YEARS\n";
		}		
	}

	return 0;
}