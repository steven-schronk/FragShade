#include <iostream>
#include <climits>
#include "tga.h"

#define WIDTH 800
#define HEIGHT 500

using namespace std;

int main(){
	TGA p(WIDTH, HEIGHT);
	BLOCK_t *from = new BLOCK_t;
	POINT_t *to = new POINT_t;

	p.set_px(10, 10, 255, 255, 255);
	p.cp_px(10,10,50,50);

	from->start_x = 0;
	from->start_y = 0;
	from->stop_x = 10;
	from->stop_y = 10;
	to->x=11;
	to->y=11;
	p.cp_px_block(from, to);

	p.write_truecolor_tga("pic.tga");
	cout << "Image Creation Complete" << endl;
	return 0;
}
