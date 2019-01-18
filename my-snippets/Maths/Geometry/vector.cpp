struct vec { double x, y;
	vec(double _x, double _y) : x(_x), y(_y) {} 
};
	
vec toVec(point a, point b) { // convert 2 points to vector a->b
	return vec(b.x - a.x, b.y - a.y); 
}

vec scale(vec v, double s) { // nonnegative s = [<1 .. 1 .. >1]
	return vec(v.x * s, v.y * s); 
}

point translate(point p, vec v) { // translate p according to v
	return point(p.x + v.x , p.y + v.y); 
}

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }