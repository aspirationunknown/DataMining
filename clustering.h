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
	point location; //x & y coordinates of this record
	int centroid; //the index of the closest centroid
	double distance_from_centroid; //distance from the closest centroid
};