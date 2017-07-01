#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;
int s[1000000],arr[1000000],parent[1000000];


int bSearch(int start, int end , int target){
	while(end-start > 1){
		int mid = start + (end-start)/2;
		if (arr[s[mid]] >= target)
		{
			end = mid;
		}else{
			start = mid;
		}
	}
	return end;
}

int main(){
	std::ios::sync_with_stdio(false);
	int n=0,temp,len=1;

	while(cin>>temp){
		arr[n++]=temp;
	}

	s[0]=0;
	parent[0]=-1;

	F(i, 1, n){
		if (arr[i] < arr[s[0]])
		{
			//we have a new smallest number for the start of the subsequence
			s[0]=i;
		}else if (arr[i] > arr[s[len-1]])
		{
			//appending that index to the end
			parent[i]=s[len-1];
			s[len++]=i;			
		}else{
			//use binary search to find the smallest number greater than this number
			int pos = bSearch(-1, len-1, arr[i]);
			parent[i]=s[pos-1];
			s[pos]=i;
		}
	}
	cout<<len<<"\n";
	cout<<"-"<<"\n";
	stack<int> ans;

	for (int i = s[len-1]; i >=0; i = parent[i])
	{
		ans.push(arr[i]);
	}

	while(!ans.empty()){
		cout<<ans.top()<<"\n";
		ans.pop();
	}
	return 0;
}