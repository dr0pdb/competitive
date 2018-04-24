#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
using namespace std;
bool sol;
std::vector<int> v;
std::map<vector<int>, bool> solutionExists;

void backtrack(int list[], int total, int n, int sum,int i){
	int prev=0;
	if (sum == total)
	{
		if (solutionExists[v])
		{
			return;
		}else{
			solutionExists[v]=true;
		}
		sol = true;
		//print the contents of the vector
		for (int j = 0; j < v.size(); ++j)
		{
			if (j==0)
			{
				cout<<v[j];
			}else{
				cout<<"+"<<v[j];
			}
		}
		cout<<"\n";
	}

	if (i == n)
	{
		return;
	}

	
	//taking the number
	sum+=list[i];
	v.push_back(list[i]);
	backtrack(list,total,n,sum,i+1);
	sum-=list[i];
	v.pop_back();
	
	
	//leaving the number
	backtrack(list, total, n, sum, i+1);
	
}

void solve(int list[], int total , int n){
	int sum;
	for (int i = 0; i < n; ++i)
	{
		sum=0;
		backtrack(list,total,n,sum,i);
	}
}

int main(){
	int total, n;
	while(cin>>total>>n && total && n){
		int list[n];
		solutionExists.clear();
		for (int i = 0; i < n; ++i)
		{
			cin>>list[i];
		}
		cout<<"Sums of "<<total<<":"<<"\n";
		sol = false;

		solve(list,total,n);
		if (!sol)
		{
			cout<<"NONE"<<"\n";
		}
	}
	return 0;
}