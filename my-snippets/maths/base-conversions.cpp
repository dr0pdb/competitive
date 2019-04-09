// A list of symbol. Depending on base and number system, this list can be different.
char symbol[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
string decimalToBase ( int x, int base ) {
    string res = "";
 
    while ( x ) {
        int r = x % base; // Find the last digit
        res = res + symbol[r]; // Change the integer value to symbol and append to res
        x /= base; // Remove the last digit
    }
    if ( res == "" ) res = symbol[0]; // If res is empty, that means x is 0.
    reverse ( res.begin(), res.end()); // We found the digits in reverse order.
    return res;
}

int baseToDecimalAlternate ( string x, int base ) {
    int res = 0;
    int len = x.length();
 
    for ( int i = 0; i < len; i++ ) {
        res = ( res * base ) + (x[i]-'0');
    }
    return res;
}

int baseToDecimal ( string x, int base ) {
    int res = 0;
    int len = x.length();
 
    int coef = 1; // initially base^0
    for ( int i = len - 1; i >= 0; i-- ) { // Start from reverse
        res += (x[i]-'0') * coef;
        coef *= base; // increase power of base
    }
    return res;
}