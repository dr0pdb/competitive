vll getDivisors(ll n) 
{ 
	vll facts;
    for (ll i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            if (n/i == i) 
            	facts.push_back(i);     
  
            else {
            	facts.push_back(i);
            	facts.push_back(n/i);
            } 
               
        } 
    } 
    return facts;
}