#include<bits/stdc++.h>
using namespace std;

//fast method to read integers
void fastscan(long long &number)
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

     ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        

    long long noBooks,timegiven;
    fastscan(noBooks);
    fastscan(timegiven);

    long long bookTime[noBooks];
    long long total=0,maximum=0,j=0;

    for (size_t i = 0; i < noBooks; i++)
    {
        fastscan(bookTime[i]);
        total+=bookTime[i];

        if (total>timegiven)
        {
            total-=bookTime[j];
            j++;
        }

        if (i-j+1>maximum)
        {
            maximum=i-j+1;
        }
    }

    
   
    cout<<maximum<<"\n" ;

    return 0;
}