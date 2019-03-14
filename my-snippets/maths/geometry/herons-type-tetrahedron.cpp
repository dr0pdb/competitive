/*
For a tetrahedron ABCD.
	w = AB
	v = AC
	u = AD
	U = BC
	V = BD
	W = CD
*/

cin >> w >> v >> u >> U >> V >> W;
		double X = (w - U + v) * (U + v + w);
		double x = (U - v + w) * (v - w + U);
		double Y = (u - V + w) * (V + w + u);
		double y = (V - w + u) * (w - u + V);
		double Z = (v - W + u) * (W + u + v);
		double z = (W - u + v) * (u - v + W);
		double a = sqrt(x * Y * Z);
		double b = sqrt(X * y * Z);
		double c = sqrt(X * Y * z);
		double d = sqrt(x * y * z);
		double ans = -a + b + c + d;
		ans *= a - b + c + d;
		ans *= a + b - c + d;
		ans *= a + b + c - d;
		ans = sqrt(ans) / (192.0 * u * v * w);
		cout << ans << endl;