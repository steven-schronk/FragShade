#ifndef POLYGON_T
#define POLYGON_T
#include <list>
#include "point.h"

class polygon_t {
public:
	polygon_t();
	~polygon_t();
	void add_point(point_t p);
	void draw_polygon();
private:
	// polygon consists of a list of points.
	std::list<point_t> points;

};
#endif
