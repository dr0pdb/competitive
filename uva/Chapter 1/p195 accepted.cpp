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

bool compare (char a, char b)
{
    bool lowerA = true, lowerB= true;
    if (a >= 'A' && a <= 'Z') 
        lowerA = false;
    if (b >= 'A' && b <= 'Z') 
        lowerB = false;
 
 
    if (lowerA && lowerB) 
        return a < b;
    if (!lowerA && !lowerB) 
        return a < b;
    
 
    if (lowerA)
    {
        a -= ('a'-'A');
        return a < b;
    }
    else
    {
        b -= ('a'-'A');
        return a <= b;
    }
}
int main(){

      

     int noStrings;
     fastscan(noStrings);

     string temp;

     while (noStrings--)
     {
        getline(cin,temp);        
        
        
        sort(temp.begin(),temp.end(),compare);

        do
        {
            std::cout << temp << "\n";
        } while(next_permutation(temp.begin(),temp.end(),compare));
        
     }


       
           return 0;    
}
