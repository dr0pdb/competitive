#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;

int main(){
	//std::ios::sync_with_stdio(false);
	//int arr[10050];
	int n;

	while(cin>>n && n){
		int max=0,sum=0;
		int temp;
		F(i,0,n){
			//cin>>arr[i];
			scanf("%d",&temp);
			sum+=temp;
			if (sum>max)
			{		
				max=sum;
			}
			if (sum<0)
			{
				sum=0;
			}
		}
		if (max>0)
		{
			cout<<"The maximum winning streak is "<<max;
		}
		else{
			cout<<"Losing streak";
		}
		cout<<".\n";
	}
	return 0;
}