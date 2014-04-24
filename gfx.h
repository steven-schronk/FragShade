#ifndef GFX_H_
#define GFX_H_

#include "point.h"

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768

void set_pix(int x, int y, float r, float g, float b);
void draw_line(point_t start, point_t stop);
#endif /* GFX_H_ */
