/****************************************************************************
* \file MPI K-Means Clustering
* 
* \author Charles Parsons
*
* \date December 9, 2015
*
* \professor Dr. Karlsson
*
* \class CSC 692 - Data Mining
*
* \description
*
* \usage ./mpi_cluster <number of nodes> <number of clusters>
*
* **************************************************************************/
//#include <mpi.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "clustering.h"


int main(int argc, char* argv[])
{
	int i; //loop counter
	int n_centroids;
	point* centroids;
	//start out with k-means clustering algorithm
	//then convert into parallel version with proper MPI send/recv

	//seed random number generator
	srand(time(NULL));

	//determine range for x and y values for choosing random points
	
	//read in records from data file and store in a dynamically allocated
	//array of records

	//create the dynamic array for the centroids, using the value in argv[2]
	n_centroids = atoi(argv[2]);
	centroids = new(std::nothrow) point[n_centroids];

	//start timing

	//create n_centroids number of random centroids and store in an array
	for(i = 0; i < n_centroids; ++i)
	{
		centroids[i].x = rand() % 100;
		centroids[i].y = rand() % 100;
	}

	//calculate distance from each centroid to each point, storing
	//the index of the closest centroid to that point in the record

	//calculate the mean of both x & y for each point associated with each
	//centroid and move the centroid's coordinates to those means.

	//recalculate the distance from each centroid to each point, store the index
	//of the centroid closest to each point. keep a count of how many points
	//change from one centroid to another.

	//recalculate the mean x & y of each of the points associated with each
	//centroid.
	//keep doing this until a certain percentage of points do not change
	//which centroid they are closest to.

	//end timing

	//output the total time elapsed as well as how many nodes were used.

	//output to a file the list of centroids and the points that were
	//closest to them. make this a csv file with the following format:
	//centroid index, record x coordinate, record y coordinate 
	//have only one record per line.

	//deallocate centroids array
	delete [] centroids;

	return 0;
}