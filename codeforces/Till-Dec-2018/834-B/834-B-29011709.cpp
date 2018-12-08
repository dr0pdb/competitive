#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);

	int n,k;
	cin>>n>>k;

	string order;
	cin>>order;

	bool found[26]={false};
	//initial and final occurences
	int times[26][2]={-1};
	F(i, 0, order.length()){
		if (found[order[i]-'A'])
		{
			times[order[i]-'A'][1]=i;	
		}else{
			times[order[i]-'A'][0]=i;
            times[order[i]-'A'][1]=i;
			found[order[i]-'A']=true;
		}
	}
	bool ans=false;
	F(i, 0, order.length()){
		int counter=0;
		F(j, 0, 26){
			if (times[j][1]>= i && times[j][0] <=i && found[j])
			{
				counter++;
			}
		}
		if (counter > k )
		{
			ans=true;
			break;
		}
	}

	if (ans)
	{
		cout<<"YES";
	}else{
		cout<<"NO";
	}
	return 0;
}