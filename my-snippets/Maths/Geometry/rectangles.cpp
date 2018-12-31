/*
	Let a rectangle(x1,y1,x2,y2): x1,y1 are the coordinates of bottom left and x2,y2 are the for top right.

	So let two rectangles A(x1,y1,x2,y2) and B(x3,y3,x4,y4).
	A and B insersect do not intersect if: max(x1,x3)>min(x2,x4)  or max(y1,y3)>min(y2,y4)
	If they intersect then their intersection is the rectangle: (max(x1,x3),max(y1,y3),min(x2,x4),min(y2,y4))
*/