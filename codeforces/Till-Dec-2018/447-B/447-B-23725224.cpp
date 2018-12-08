#include<bits/stdc++.h>
using namespace std;


int main()
{
	string word;
	cin>>word;

	int k;
	cin>>k;
	
	int values[26];
	int tempvalue;
	int result=0;
	for (int i = 0; i < 26; i++)
	{
		cin>>tempvalue;
		values[i]=tempvalue;

	}	
	
	for (int  i = 0; i < word.length(); i++)
	{
		result+=(i+1)*values[word[i]-'a'];
	}

	sort(values,values+26);

	int i=word.length();
	while (k--)
	{
		result+=(++i)*values[25];
		
	}

	cout<<result<<endl;
	


	return 0;
}