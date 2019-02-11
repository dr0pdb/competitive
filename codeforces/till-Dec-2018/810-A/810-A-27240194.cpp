#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
using namespace std;

int main()
{	
    std::ios::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	int marks[n],sum=0,count=0;
	for (int i = 0; i < n; ++i)
	{
		cin>>marks[i];
		sum+=marks[i];
	}
	
	double average = double(sum)/(double)n;
	if (ceil(average)-average > average-floor(average))
	{
		average=floor(average);
	}else{
		average=ceil(average);
	}
	average = ceil(average);
	while(average<k){
		sum+=k;
		n++;
		average=double(sum)/(double)n;
		if (ceil(average)-average > average-floor(average))
		{
			average=floor(average);
		}else{
			average=ceil(average);
		}
		count++;
	}
	cout<<count;
	return 0;
}