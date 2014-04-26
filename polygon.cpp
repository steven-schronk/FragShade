#include <array>
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
#include "edge.h"
#include "edge_list.h"
#include "gfx.h"
#include "polygon.h"

using namespace std;

polygon_t::polygon_t(){

}

polygon_t::~polygon_t(){

}

void polygon_t::add_point(point_t p){
	points.push_back( p);
}

// TODO: Draw each edge of polygon in list
void polygon_t::draw_polygon(){

}

void polygon_t::draw_filled_polygon(){
	list<point_t>::const_iterator i;
	list<point_t>::const_iterator j = points.end();
	int point_count = points.size();
	double nodeX[point_count];
	for(int pixelY = 0; pixelY < WINDOW_HEIGHT; ++pixelY){ // move through entire scene one scan line at a time
		// find intersections of the scan line with all edges of polygon
		int nodes = 0;
		j = points.end();
		for(i = points.begin(); i != points.end(); i++){
			cout << i->getx() << ":" << i->gety() << endl;
			if ((i->gety() < (double) pixelY && j->gety() >= (double) pixelY)
			    ||  (j->gety() < (double) pixelY && i->gety() >= (double) pixelY)){
					//nodeX[nodes++] = 2.0;
					// nodeX[nodes++]=(int)(polyX[i] + (pixelY-polyY[i])  /(polyY[j] -polyY[i])
					nodeX[nodes++] = (int)(i->getx() + (pixelY- i->gety())/(j->gety()-i->gety())
						*(j->getx()-i->getx()));
			}
			j = i;
		}
		// sort intersections by increasing x coordinate
		//std::sort(nodeX, nodeX + point_count);
		int swap;
		int k=0;
		while(k<nodes-1) {
		    if(nodeX[k]>nodeX[k+1]) {
		    	swap=nodeX[k];
		    	nodeX[k]=nodeX[k+1];
		    	nodeX[k+1]=swap;
		    	if (k) k--;
		    }
		    else k++;
		}
		// moving through list of increasing x intersections
		for (int i=0; i<nodes; i+=2) {
			if(nodeX[i]>=WINDOW_WIDTH) break;
			if(nodeX[i+1]> 0 ) {
				if (nodeX[i]<0) nodeX[i]= 0;
				if (nodeX[i+1]>WINDOW_WIDTH) nodeX[i+1] = WINDOW_WIDTH;
				for (int k=nodeX[i]; k<nodeX[i+1]; k++){
					set_pix(k, pixelY, 1.0, 1.0, 1.0);
					std::cout << k << ":" << pixelY << std::endl;
				}
			}
		}
	}
}
