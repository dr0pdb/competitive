#include<bits/stdc++.h>
using namespace std;
#include<string>


int main()
{
	
	int n;
	cin>>n;

	if (n>=0)
	{
		cout<<n<<endl;
	}
	
	else
	{

		int oncedeleted;
		int tensdeleted;

		oncedeleted=n/10;
		tensdeleted=((n/100)*10)+(n%10);

		if (oncedeleted>tensdeleted)
		{
			cout<<oncedeleted<<endl;
		}

		else
		{
			cout<<tensdeleted<<endl;
		}	
	}

	return 0;
}