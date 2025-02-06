#include "Point.hpp"

bool bsp(const Point a, const Point b,const Point c,const Point point)
{
	Fixed x = (b.get_x() - a.get_x()) * (point.get_y() - a.get_y()) - (b.get_y() - a.get_y()) * (point.get_x() - a.get_x());
    Fixed y = (c.get_x() - b.get_x()) * (point.get_y() - b.get_y()) - (c.get_y() - b.get_y()) * (point.get_x() - b.get_x());
    Fixed z = (a.get_x() - c.get_x()) * (point.get_y() - c.get_y()) - (a.get_y() - c.get_y()) * (point.get_x() - c.get_x());
	if ((x > 0 and y > 0 and z > 0) or (x < 0 and y < 0 and z < 0))
		return true;
	return false;
}