#include <cassert>
#include <fstream>
#include <string>
#include "tga.h"

using namespace std;

TGA::TGA(int w, int h){
	// TODO: test for unreasonable values
	width = w;
	height = h;
	px = new PIXEL_t *[width];
	for(unsigned int i = 0; i < width; ++i){
	   px[i] = new PIXEL_t[height];
	   for(int j = 0; j < height; j++){
		   px[i][j].red   = 0;
	       px[i][j].green = 0;
		   px[i][j].blue  = 0;
	   }
	}
}

void TGA::cp_px(int startx, int starty, int stopx, int stopy){
	px[stopx][stopy].red   = px[startx][starty].red;
	px[stopx][stopy].green = px[startx][starty].green;
	px[stopx][stopy].blue  = px[startx][starty].blue;
}

void TGA::set_px(int width, int height, int red, int green, int blue){
	// TODO: test for unreasonable values
	assert(width < this->width);
	assert(height < this->height);
	assert(width >= 0);
	assert(height >= 0);
	px[width][height].red   = red;
	px[width][height].green = green;
	px[width][height].blue  = blue;
}

void TGA::cp_px_block(BLOCK_t *from, POINT_t *to){
	assert(from);
	assert(to);
	assert(from->start_x < this->width);
	assert(from->stop_x  < this->width);
	assert(from->start_y < this->height);
	assert(from->stop_y  < this->height);
	assert(to->x < this->width);
	assert(to->y < this->height);
	// copy block to temp location
	//PIXEL_t temp_px = new PIXEL_t[from.stop_x-from.start_x][from.stop_y-from.start_y];
	 
	//int (*p)[200] = malloc(400 * sizeof *int);

	//if(!temp_px) { printf("Could Not Allocate Block of Pixels\n"); exit(-1); }
	//printf("%d\n", temp_px[0][0]);
	//write temp data to location
	for(int x = 0; x < from->stop_x-from->start_x; x++)
		for(int y = 0; y < from->stop_y-from->start_y; y++){
			//temp_px[x][y]->red = px[x][y].red;
		}
	//free(temp_px);
}

bool TGA::write_truecolor_tga( const string& filename)
  {
  ofstream tgafile( filename.c_str(), ios::binary );
  if(!tgafile) return false;

  // The image header
  byte header[ 18 ] = { 0 };
  header[  2 ] = 1;  // truecolor
  header[ 12 ] =  width        & 0xFF;
  header[ 13 ] = (width  >> 8) & 0xFF;
  header[ 14 ] =  height       & 0xFF;
  header[ 15 ] = (height >> 8) & 0xFF;
  header[ 16 ] = 24;  // bits per pixel

  tgafile.write( (const char*)header, 18 );
  // The image data is stored bottom-to-top, left-to-right
	for(int y = height -1; y >= 0; y--)
		for(unsigned int x = 0; x < width; x++){
			tgafile.put( px[x][y].blue  );
			tgafile.put( px[x][y].green );
			tgafile.put( px[x][y].red   );
		}
  // The file footer. This part is totally optional.
  static const char footer[ 26 ] =
    "\0\0\0\0"  // no extension area
    "\0\0\0\0"  // no developer directory
    "TRUEVISION-XFILE"  // yep, this is a TGA file
    ".";
  tgafile.write( footer, 26 );
  tgafile.close();
  return true;
}
