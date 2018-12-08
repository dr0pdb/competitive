#include<bits/stdc++.h>
using namespace std;


int main()
{
	int row,column;
	cin>>row>>column;

	for (int i = 1; i <= row; i++)
	{
		if (i%2==1)
		{
			for (int x = 0; x < column; x++)
			{
				if (x<column-1)
				{
					cout<<'#';	
				}
				else{
					cout<<'#'<<endl;
				}

			}

		}

		else
		{
			if (i%4==0)
			{
				for (int x = 0; x < column; x++)
				{
					if (x==0)
					{
						cout<<'#';
					}

					else if (x==column-1)
					{
						cout<<'.'<<endl;
					}
					else
					{
						cout<<'.';
					}
				}

			}

			else
			{
				for (int x = 0; x < column; x++)
				{
					if (x<column-1)
					{
						cout<<'.';
					}
					else
					{
						cout<<'#'<<endl;
					}
				}

			}


		}
	}



	return 0;
}