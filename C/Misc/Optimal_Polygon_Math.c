/*
Given a polygon with N vertexes and N edges. There is an int number(could be negative) on every vertex and an operation in set(*,+) on every edge. Every time, we remove an edge E from the polygon, merge the two vertexes linked by the edge(V1,V2) to a new vertex with value: V1 op(E) V2. The last case would be two vertexes with two edges, the result is the bigger one. 
Return the max result value can be gotten from a given polygon.
*/

void getNew(int *v, int *newv, int *e, int *newe, int i, int val, int len) {
	int j;	
	for (j=0; j<len; j++)
		if (j == i || j == (i+1)%len)
			vnew[j]=val;
		else if (j<i)
			vnew[j] = v[j];

		else
			vnew[j] = v[(j+1)%len];

		if (j<i)
			enew[j] = e[j];
		else
			enew[j] = e[(j+1)%len];
}

int getMax(int *v, char *e, int len) {
	int max = -9999, i, val, curr, vnew[MAX];
	char enew[MAX];

	for (i=0; i<len; i++) {
		val = operation(v[i],e[i],v[(i+1)%len]);
		getNew(v,newv,e,newe,i,val,len);
		curr = val + getMax(newv,newe,len-1);
		if(curr > max)
			max = curr;
	}
	return max;
}
