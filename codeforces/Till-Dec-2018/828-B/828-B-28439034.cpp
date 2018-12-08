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
	
	int r,c;
	cin>>r>>c;
	int counter=0;
	char cells[r][c];
	int mini=100000,minj=100000,maxi=-1,maxj=-1;
	F(i, 0, r){
		F(j, 0, c){
			cin>>cells[i][j];
			if(cells[i][j] == 'B'){
				if (i<mini)
				{
					mini = i;
				}
				if (i > maxi)
				{
					maxi = i;
				}
				if (j < minj)
				{
					minj= j;
				}
				if (j > maxj)
				{
					maxj = j;
				}
			}
		}
	}

	if (mini==100000 || minj==100000 || maxi ==-1 ||maxj == -1)
	{
		cout<<1<<"\n";
	}else{
		int irange = abs(maxi - mini+1);
		int jrange = abs(maxj - minj+1);

		bool igreater = false;
		bool jgreater = false;

		if (irange > jrange)
		{
			igreater=true;
		}else{
			jgreater = true;
		}

		if (max(irange,jrange) > r || max(irange,jrange) > c)
		{
			cout<<-1<<"\n";
		}else{
			
			F(i, mini, maxi+1){
				F(j, minj, maxj+1){
					if (cells[i][j] == 'W')
					{
						counter++;
					}
				}
			}

			counter+= abs(irange- jrange)* max(irange,jrange);
			cout<<counter<<"\n";
		}

	}
	
	return 0;
}