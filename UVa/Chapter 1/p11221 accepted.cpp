#include<bits/stdc++.h>
using namespace std;


void fastscan(int &number)
{

    bool negative = false;
    register int c;
 
    number = 0;
 

    c = getchar();
    if (c=='-')
    {

        negative = true;
 

        c = getchar();
    }
 
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
 
    if (negative)
        number *= -1;
}

int main(){

    int testcase;
    fastscan(testcase);

    string line,temp;

    for (int x=1;x<=testcase;x++)
    {   
        printf("Case #%d:\n",x);
        getline(cin,line);
        bool magic=true;
        temp="";
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i]>='a' && line[i]<='z')
            {
                temp=temp+line[i];
            }
        }
        
        int root=sqrt(temp.length());
        if ((root*root)==temp.length())
        {
                int counter=0;
                char matrix[root][root];
                for (size_t i = 0; i < root; i++)
                {
                    for (size_t j = 0; j < root; j++)
                    {
                        matrix[i][j]=temp[counter++];
                    }
        
                }

                for (size_t i = 0; i < root; i++)
                {
                    for (size_t j = 0; j < root; j++)
                    {
                        if (matrix[i][j]!= matrix[j][i] || matrix[i][j]!=matrix[root-1-i][root-1-j] || matrix[i][j]!=matrix[root-1-j][root-1-i])
                        {
                                magic=false;
                                break;
                        }
                        
                    }
                }




        }

        else
        {
            magic=false;
        }

        if (magic)
        {
            printf("%d\n",root);
        }
        else
        {
            printf("No magic :(\n");
        }
    }     
           return 0;    
}
