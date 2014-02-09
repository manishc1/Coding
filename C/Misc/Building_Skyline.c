/*
Given a set of 2D coordinates for the 4 corners of each building in a city skyline, find the outline of all the buildings. Buildings may or may not overlap.
*/

typedef struct building {
	int x1,y1,x2,y2,x3,y3,x4,y4;
} building;

typedef struct edge {
	int x, h;
} edge;

int getedge (building *a, int n, edge *e) {
	int i, m=0;
	for (i=0; i<n; i++) {
		e[m].x = a.x1;
		e[m++].h = a.y2 - a.y1;
		e[m].x = a.x4;
		e[m++].h = a.y3 - a.y4;
	}
	return m;
}

printSkyline(building *a, int n) {
	edge e[100];
	int m;

	m = getedge(a, n, e);

	sort_on_x(e, m);

	for (i=0; i<m; i++) {
		maxh = e[i].h;
		j = i;
		while(e[j].x == x) {
			if (maxh < e[j].h)
				
			j++;
		}
		j--;
		
	}
}