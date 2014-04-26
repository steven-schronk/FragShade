#ifndef EDGE_LIST_H_
#define EDGE_LIST_H_

#include "edge.h"
#include "point.h"

class edge_list_t{
public:
	//edge_list_t(point_t *);
	edge_list_t();
	~edge_list_t();
	//virtual void fill(void (point_t::*)(double));
	void insert_edge(const point_t&, const point_t&);
protected:
	void include();
	void exclude();
	//virtual void swap();
	//virtual void update();
	edge_t* head;
	edge_t* right;
	double scan;
	double scan_decrement;
};
#endif /* EDGE_LIST_H_ */
