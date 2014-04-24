#ifndef POINT_T
#define POINT_T

class point_t {
public:
	point_t();
	point_t(double, double);
	//point_t(const point_t&);

	point_t operator + (const point_t&) const;
	point_t operator - (const point_t&) const;
	point_t operator * (double) const;
	point_t operator / (double) const;
	point_t& operator += (const point_t&);
	point_t& operator -= (const point_t&);
	point_t operator - () const;

	double givx() const { return x; }
	double givey() const { return y; }
	virtual double givez() const { return 0; }
	virtual void set(const point_t& p) { x = p.x; y = p.y; }
	void setx(double x) { point_t::x = x; }
	void sety(double y) { point_t::y = y; }
	double getx();
	double gety();
	void draw_point();
	//void sety(double z) { point_t::z = z; }
private:
	double x;
	double y;
	//int z = 0;
};
#endif
