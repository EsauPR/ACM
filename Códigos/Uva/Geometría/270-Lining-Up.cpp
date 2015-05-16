//270 Lining Up

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <cstdlib>
#include <complex>
#include<cstdio>
#include<cstring>
 
using namespace std;
 
struct point {
 int x, y;
};
 
struct line {
 vector<point> P;
 
 void add(const point &p) {
 	P.push_back(p);
 }
 int size() {
 	return P.size();
 }
 bool contain(const point &p) {
 	int s = size(), c = 0;
 	for (c = 0; c < s; c++)
 		if (p.x == P[c].x && p.y == P[c].y)
 			return true;
	return false;
 }
 void print() {
	 int n = size();
	 for (int i = 0; i < n; ++i)
	 printf("(%4d,%4d)", P[i].x, P[i].y);
 }
};
 
bool collinear(const point &p1, const point &p2, const point &p3) {
	return (p1.y - p2.y) * (p1.x - p3.x) == (p1.y - p3.y) * (p1.x - p2.x);
}
 
bool exist(vector<line> &v, const point &p1, const point &p2) {
	 int c = v.size(), k = 0;
	 for (k = 0; k < c; k++) {
		 if (v[k].contain(p1) && v[k].contain(p2))
 			return true;
	 }
	 return false;
}
 
int solve(vector<point> &pts) {
	 int i, j, k, n = pts.size();
	 int max = 0;
	 vector<line> lines;
	 for (i = 0; i < n; i++) {
		 for (j = i + 1; j < n; ++j) {
			 if (exist(lines, pts[i], pts[j]))
 				continue;
			 line line;
			 line.add(pts[i]), line.add(pts[j]);
			 for (k = j + 1; k < n; k++)
				 if (collinear(pts[i], pts[j], pts[k]))
					 line.add(pts[k]);
				 if (line.size() > max)
					 max = line.size();
		 }
	 }
	 return max;
}

int main() {
 
	int tc;
 	scanf("%d\n", &tc);
 
	while (tc--) {
		 vector<point> pts;
 
		 char line[128];
		 while (cin.getline(line, sizeof(line))) {
 
			 if (strlen(line) == 0)
			 	break;
	 
			 point p;
			 sscanf(line, "%d%d", &p.x, &p.y);
	 
			 pts.push_back(p);
 		}
 
		int max = solve(pts);
 
		printf("%d\n", max);
			 if (tc != 0)
		 		putchar('\n');
 	}
	return 0;
}
