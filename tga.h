#include <fstream>
#include <string>
using namespace std;

typedef unsigned char byte;
typedef struct{ byte red, green, blue; } PIXEL_t;
typedef struct{ unsigned int start_x, start_y, stop_x, stop_y; } BLOCK_t;
typedef struct{ unsigned int x, y; } POINT_t;

class TGA {
private:
	PIXEL_t **px;
	unsigned int width, height;
public:
	TGA(int width, int height);

	bool write_truecolor_tga( const string& filename);

	void set_px(int width, int height, int red, int green, int blue);
	// set_px(float red, float green, float blue);

	//set_clear(int red, int green, int blue);
	//set_clear(float red, float green, float blue);

	// block_px(int startx, int starty, int stopx, int stopy, int red, int green, int blue);
	// clear_block_px(int startx, int starty, int stopx, int stopy, int red, int green, int blue);

	// copy single pixel from one location to another
	void cp_px(int startx, int starty, int stopx, int stopy);

	// copy block of pixels from one location to another
	void cp_px_block(BLOCK_t *from, POINT_t *to);
};
