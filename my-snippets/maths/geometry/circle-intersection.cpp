// checks if two circles intersect or not.

long double x[110],y[110],r[110];

bool intersect(int ff, int ss) {
	long double distc = (x[ff]-x[ss])*(x[ff]-x[ss]) + (y[ff]-y[ss])*(y[ff]-y[ss]);

	if(distc < (r[ss]+r[ff])*(r[ss]+r[ff]) && distc > (r[ss]-r[ff])*(r[ss]-r[ff])) {
		return true;
	}

	return false;
}