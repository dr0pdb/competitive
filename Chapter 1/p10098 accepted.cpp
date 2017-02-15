#include<bits/stdc++.h>
using namespace std;

//fast method to read integers
void fastscan(int &number)
{
    //variable to indicate sign of input number
    bool negative = false;
    register int c;
 
    number = 0;
 
    // extract current character from buffer
    c = getchar();
    if (c=='-')
    {
        // number is negative
        negative = true;
 
        // extract the next character from the buffer
        c = getchar();
    }
 
    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
 
    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}


int main(){

      

     int noStrings;
     fastscan(noStrings);

     string temp;

     while (noStrings--)
     {
        getline(cin,temp);        
        
        
        sort(temp.begin(),temp.end());

        cout<<temp<<"\n";
        while (next_permutation(temp.begin(),temp.end()))
        {
            cout<<temp<<"\n";
        }

        printf("\n");
     }


       
           return 0;    
}
