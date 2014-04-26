#ifndef EDGE_H_
#define EDGE_H_

class point_t;

class edge_t{
public:
	edge_t(const point_t&, const point_t&);
	virtual ~edge_t(){}
	double give_y_max() { return y_max; }
	double give_y_min() { return y_min; }
	double givex() { return x; }
	edge_t* give_next() { return next; }
	void set_next(edge_t * e) { next = e; }
	edge_t** give_add_rnext() { return &next; }
	virtual void update();
	virtual void solidscan(double);
	virtual void hatchscan(double);
	virtual void patternscan(double);
protected:
	double y_max, y_min, dx, x;
	edge_t* next;
};

#endif /* EDGE_H_ */
