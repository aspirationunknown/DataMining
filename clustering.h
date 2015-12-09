/****************************************************************************
*
* \file
*
****************************************************************************/
#ifndef CLUSTERING_H
#define CLUSTERING_H

#include <iostream>

typedef long long ll;

struct point
{
	double lat; //lattitude
	double lon; //longitude
};

struct record
{
	point location; //lattitude & longitude coordinates of this record
	ll centroid; //the index of the closest centroid
	double dist; //distance from the closest centroid
	bool changed; //changed centroids
};

#endif
