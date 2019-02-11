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

	int s,v1,v2,t1,t2;
	cin>>s>>v1>>v2>>t1>>t2;

	int time1 = s*v1 + 2*t1;
	int time2 = s*v2 + 2*t2;

	if (time1 < time2)
	{
		cout<<"First";
	}else if(time1 == time2){
		cout<<"Friendship";
	}else{
		cout<<"Second";
	}
	return 0;
}