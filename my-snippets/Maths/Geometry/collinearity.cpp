bool collinear(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    return (y1-y2)*(x1-x3)==(y1-y3)*(x1-x2) ;
}