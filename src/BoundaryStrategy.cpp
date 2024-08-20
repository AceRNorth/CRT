#include <cmath>
#include "BoundaryStrategy.h"

/**
 * Calculates the shortest periodic distance between two points.
 * @details The simulation area is assumed to have toroidal (or periodic) boundaries at x = side, y = side, and x and y to be in the range [0, side].
 * @param[in] p1 first point
 * @param[in] p2 second point
 * @return The shortest distance between the points. 
 * @see Point, BoundaryStrategy::side
 */
double ToroidalBoundaryStrategy::distance(const Point &p1, const Point &p2)
{
    double x_dist = 0;
	double y_dist = 0;

	if (std::abs(p1.x - p2.x) > side - std::abs(p1.x - p2.x)) {
		x_dist = side - std::abs(p1.x - p2.x);
	} 
	else {
		x_dist = std::abs(p1.x - p2.x);
	}

	if (std::abs(p1.y - p2.y) > side - std::abs(p1.y - p2.y)) {
		y_dist = side - std::abs(p1.y - p2.y);
	}
	else {
		y_dist = std::abs(p1.y - p2.y);
	}

	return std::sqrt((x_dist * x_dist) + (y_dist * y_dist));
}

/**
 * Calculates the distance between two points. 
 * @param[in] p1 first point
 * @param[in] p2 second point
 * @return The distance between the points.
 * @see Point
 */
double EdgeBoundaryStrategy::distance(const Point &p1, const Point &p2)
{
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}