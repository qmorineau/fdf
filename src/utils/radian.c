#include "fdf.h"

double convert_angle(double angle)
{
	double radian;

	radian = (M_PI / 180) * angle;
	return (radian);
}
