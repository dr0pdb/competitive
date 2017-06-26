#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
using namespace std;
int n,m;
int vessels[1000000];

bool tryCapacity(long high){
	int count=0,sum=0;
	for(int i=0; i< n; i++){
		if (vessels[i] > high)
		{
			return false;
		}
		//count for the first vessel
		if(sum == 0 ){
			count++;
		}
		if (sum + vessels[i]>high)
		{
			count++;
			sum=0;
		}
		sum+=vessels[i];
        if (count > m)
        {
				return false;
        }
	}
	return true;
}

int main(){
	std::ios::sync_with_stdio(false);
	while(cin>>n>>m){
		for (int i = 0; i < n; ++i)
		{
			cin>>vessels[i];
		}

		//binary searching the answer range
		long low =0, high = 1000000000;
		while(high-low>0){
			if (tryCapacity(high))
			{
				high = low + (high-low)/2;
			}else{
				low = high;
				high = high + high/2;
			}
		}
		cout<<high+1<<"\n";
	}
	return 0;
}