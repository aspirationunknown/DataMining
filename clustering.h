/****************************************************************************
*
* \file
*
****************************************************************************/

struct point
{
	double x;
	double y;
};

struct record
{
	point location;
	int centroid; //the index of the closest centroid
	double distance_from_centroid; //distance from the closest centroid
};