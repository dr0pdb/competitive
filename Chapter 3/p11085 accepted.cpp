#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;
int rows[8],paths[8],minCount;

bool place(int r, int c) {
	for (int prev = 0; prev < c; prev++){
		if (paths[prev] == r || (abs(paths[prev] - r) == abs(prev - c))){
            return false;
        }
	}

	return true; 
}

void solve(int column,int counter){
	if (column == 8)
	{
		if (minCount > counter)
		{
			minCount = counter;
		}
		return;	
	}

	F(i, 0, 8){
		if (place(i,column))
		{
			paths[column] = i;
			if (i == rows[column])
			{
				solve(column+1,counter);
			}else{
				solve(column+1,counter+1);	
			}
			
			
		}
	}
	
}

int main(){
	std::ios::sync_with_stdio(false);
	int t=1;
	while(cin>>rows[0]){
		rows[0]--;
		paths[0]=rows[0];
		F(i, 1, 8){
			cin>>rows[i];
			rows[i]--;
			paths[i]=rows[i];
		}
		minCount = 1000000;
		solve(0,0);
		cout<<"Case "<<t++<<": "<<minCount<<"\n";
	}

	return 0;
}