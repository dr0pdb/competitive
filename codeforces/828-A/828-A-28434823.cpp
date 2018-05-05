#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;

int main(){
	std::ios::sync_with_stdio(false);
	
	int n,a,b;
	cin>>n>>a>>b;

	bool occs[a]={false};
	bool occd[b][2]={false};

	bool allDfilled = false;

	int t;
	int counter=0,sc=0,sd=0;
	F(i, 0, n){
		cin>>t;
		if (t==1)
		{
			if (sc < a)
			{
				occs[sc++] = true;
			}else{
				if (allDfilled)
				{
					counter++;
					continue;
				}
				bool vacFound = false;
				F(j, 0, b){
					if (!occd[j][0])
					{
						vacFound = true;
						occd[j][0]=true;
						sd++;
						break;
					}else if(!occd[j][1]){
						vacFound = true;
						occd[j][1]=true;
						sd++;
						break;			
					}
				}

				if (!vacFound)
				{
					counter++;
					allDfilled=true;
				}
			}
		}else{
			if (sd < b)
			{
				occd[sd][0]=occd[sd][1]=true;
				sd++;
			}else{
				counter+=2;
			}
		}
	}
	cout<<counter<<"\n";
	return 0;
}