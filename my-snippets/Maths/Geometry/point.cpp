struct point_i { 
	int x, y;
	point_i() { x = y = 0; }
	point_i(int _x, int _y) : x(_x), y(_y) {} 
};


struct point { 
	double x, y;
	point() { x = y = 0.0; }
	point(double _x, double _y) : x(_x), y(_y) {}

	bool operator < (point other) const {
		if (fabs(x - other.x) > eps)
			return x < other.x;
		return y < other.y; 
	}

	bool operator == (point other) const {
		return (fabs(x - other.x) < eps && (fabs(y - other.y) < eps)); 
	}
};

double dist(point p1, point p2) {
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

int dist_int (point a, point b)
{
  return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

bool mul (point a, point b, point c)
{
  return (b.x-a.x)*(c.x-b.x)+(b.y-a.y)*(c.y-b.y)==0;
}

// check if 4 pts form a rectangle.
bool rec (point a, point b, point c, point d)
{
  return (dist(a,b)==dist(c,d) && dist(a,d)==dist(b,c) && mul(a,b,c) && mul(b,c,d) && mul(c,d,a) && mul(d,a,b));
}

// check if 4 points form a square.
bool sq (point a, point b, point c, point d)
{
  return (rec(a,b,c,d) && dist(a,b)==dist(b,c));
}
