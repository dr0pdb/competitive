#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define mes(i,a) memset(a,i,sizeof(a))
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

bool possible(int dig, int sum){
	return sum>=0 && sum<=9*dig;
}

int main(){
	std::ios::sync_with_stdio(false);
	
	int m,s,copys;
	cin>>m>>s;

	if ((s<=0 && m>1) || s>9*m)
	{
		cout<<"-1 -1";
		return 0;
	}

	copys=s;
	string minm="",maxm="";


	//finding the min 
	F(i, 0, m){
		F(j, 0, 10){
			if ((i>0 || j>0 || (m==1 && j==0)) && possible(m-i-1,s-j))
			{
				minm+=char('0'+j);
				s-=j;
				break; //going for the next digit
			}
		}
		RF(j, 9, 0){
			if ((i>0 || j>0 || (m==1 && j==0)) && possible(m-i-1,copys-j))
			{
				maxm+=char('0'+j);
				copys-=j;
				break;
			}
		}
	}
	cout<<minm<<" "<<maxm;	
	
	return 0;
}