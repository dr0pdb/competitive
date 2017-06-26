#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
using namespace std;
int heights[20000];
int diameter[20000];

int main(){
	int nheads,nknights,cost;
	bool isPossible;
	while(cin>>nheads>>nknights && nheads && nknights){
		isPossible=true;
		cost=0;
		for (int i = 0; i < nheads; ++i)
		{
			cin>>diameter[i];
		}

		for (int i = 0; i < nknights; ++i)
		{		
			cin>>heights[i];
		}

		if (nknights < nheads)
		{
			isPossible=false;
			cout<<"Loowater is doomed!"<<"\n";
			continue;
		}

		sort(diameter,diameter+nheads);
		sort(heights,heights+nknights);

		int diameterIndex=0,heightIndex=0;
		while(true ){
			if (diameterIndex == nheads)
			{
				break;	
			}
			if(heightIndex == nknights){
				isPossible=false;
				break;
			}
			if (diameter[diameterIndex] <= heights[heightIndex])
			{
				cost+=heights[heightIndex];
				diameterIndex++;
				heightIndex++;
			}else{
				heightIndex++;
			}
		}

		if (isPossible)
		{
			cout<<cost<<"\n";
		}else{
			cout<<"Loowater is doomed!"<<"\n";
		}
	}
	return 0;
}