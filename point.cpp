#include "point.h"
#include "gfx.h"

point_t::point_t(){ x = 0; y = 0;}

point_t::point_t(double x1, double y1){
	x = x1;
	y = y1;
}

void point_t::draw_point(){
	set_pix(x, y, 1.0, 1.0, 1.0);
}
