//return x^y mod p
ll power(ll x,ll y, ll p)
{
    ll res = 1;     
    x = x % p; 
 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
 
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}


//return x^y
ll power(ll x,ll y)
{
    ll res = 1;     
 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x);
 
        y = y>>1; // y = y/2
        x = (x*x);  
    }
    return res;
}
