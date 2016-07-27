//184 - Laser Lines

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
	 
	 bool operator < (const struct point &p) const{
	 	 return x < p.x || (x == p.x && y < p.y);
	 }
	 bool operator == (const struct point &p) const{
	 	 return ( x == p.x && y == p.y ) ;
	 }
 
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
	 
	 void psort(){
	 	sort(P.begin(), P.end());
	 }
	 
	 void print() {
		 int n = size();
		 for (int i = 0; i < n; ++i)
		 printf("(%4d,%4d)", P[i].x, P[i].y);
	 }
	 
	bool operator < (const struct line & l) const{
		for(int i=0; i < l.P.size() && i < P.size(); i++)
		{
			if( P[i] == l.P[i] ) continue;
			return ( P[i] < l.P[i]);
		}
		return false;
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

void solve(vector<point> &pts) {
	 int i, j, k, n = pts.size();
	 int max = 0;
	 bool band = true;
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
			if(line.size()>2)
			{
				if(band) puts("The following lines were found:");
				line.print();
				puts("");
			 	band = false;
			 	lines.push_back(line);
			}
		 }
	 }
	 if(band) puts("No lines were found");
}

int main() {
	 
	while (1) {
		 vector<point> pts;
		 point p;
		 while (scanf("%d %d", &p.x, &p.y) == 2) {
			 if (p.x == 0 && p.y == 0)
				 break;
			 pts.push_back(p);
		 }
		 if (pts.size() == 0)
			 break;
		 stable_sort(pts.begin(), pts.end());
		 solve(pts);
	 }
	 return 0;
}
