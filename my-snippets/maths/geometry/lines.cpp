struct line { double a, b, c; };

// the answer is stored in the third parameter (pass by reference)
void pointsToLine(point p1, point p2, line &l) {
	if (fabs(p1.x - p2.x) < eps) {
		l.a = 1.0; l.b = 0.0; l.c = -p1.x;
	} else {
		l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
		l.b = 1.0;
		l.c = -(double)(l.a * p1.x) - p1.y;
	}
}


// integer coordinates

typedef pair<ll,ii> line; // c, {a, b} for ax - by = c.

// ax - by = c
line create(ii p1, ii p2) {
    int x1 = p1.ff, x2 = p2.ff;
    int y1 = p1.ss, y2 = p2.ss;


    int a = y1 - y2, b = x1 - x2;
    int d = __gcd(abs(a), abs(b)); 
    if(d) {
        a /= d, b /= d;
    }
    if (a < 0 || (a == 0 && b < 0))
    {
        a = -a;
        b = -b;
    }
    std::pair<int,int> slope(a, b);
    long long c = 1LL * a * x1 - 1LL * b * y1;

    return {c, {a, b}};
}