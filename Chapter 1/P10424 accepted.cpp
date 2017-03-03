#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<string>
using namespace std;

int main()
{
	string name1;
	string name2;
	while (getline(cin,name1))
	{
		getline(cin,name2);

		int value1=0;
		int value2=0;

		for (int i = 0; i < name1.size(); i++)
		{
			if (isupper(name1[i]))
			{
				value1+=name1[i]-'A'+1;
			}

			else if (islower(name1[i]))
			{
				value1+=name1[i]-'a'+1;
			}
		}
		

		for (int i = 0; i < name2.size(); i++)
		{
			if (isupper(name2[i]))
			{
				value2+=name2[i]-'A'+1;
			}

			else if (islower(name2[i]))
			{
				value2+=name2[i]-'a'+1;
			}
		}

		if (value1%9==0)
		{
			value1=9;
		}
		
		else
		{
			value1%=9;
		}

		if (value2%9==0)
		{
			value2=9;
		}
		
		else
		{
			value2%=9;
		}


		 if(value1>=value2) printf("%.2f %c\n",value2*100.0/value1,'%');
		else printf("%.2f %c\n",value1*100.0/value2,'%');	

	}



	return 0;
}

