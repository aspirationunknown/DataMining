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
* \usage ./mpi_cluster <number of clusters>
*
* **************************************************************************/
//#include <mpi.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "clustering.h"


int main(int argc, char* argv[])
{
	point* centroids; //array for the centroids
	ll n_changed = 0;
	ll* counts;
	record* data;
	double distance = 0.0;
	bool keep_going = true;
	ll i, j; //loop counter
	point* means; //to store the mean lat & lon for each centroid
	ll n_centroids = 0;
	ll n_data_points = 10000;
	


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
	//create the dynamic array for the means of the cluster data points lat &
	//lon
	means = new(std::nothrow) point[n_centroids];
	counts = new(std::nothrow) ll[n_centroids];
	//create the dynamic array for the data points
	data = new(std::nothrow) record[n_data_points];

	//check for memory allocation success
	if(centroids == nullptr || means == nullptr || counts == nullptr ||
		data == nullptr)
	{
		std::cerr << "Memory allocation failure. Exiting." << std::endl;
		delete [] centroids;
		delete [] means;
		delete [] counts;
		delete [] data;
		return -1;
	}
	//start timing

	for(i = 0; i < n_data_points; ++i)
	{
		data[i].location.lat = double(rand() % 1000);
		data[i].location.lon = double(rand() % 1000);
		data[i].centroid = -1;
		data[i].dist = 9999999;
		data[i].changed = false;
	}

	//create n_centroids number of random centroids and store in an array
	for(i = 0; i < n_centroids; ++i)
	{
		centroids[i].lat = double(rand() % 1000);
		centroids[i].lon = double(rand() % 1000);
	}

	//recalculate the distance from each centroid to each point, store the index
	//of the centroid closest to each point. keep a count of how many points
	//change from one centroid to another.
	//recalculate the mean lat & lon of each of the points associated with each
	//centroid.
	//keep doing this until a certain percentage of points do not change
	//which centroid they are closest to.
	while(keep_going)
	{
		n_changed = 0;
		//calculate distance from each centroid to each point, storing
		//the index of the closest centroid to that point in the record
		for(i = 0; i < n_data_points; ++i)
		{
			for(j = 0; j < n_centroids; ++j)
			{
				distance = sqrt((centroids[j].lat - data[i].location.lat) * 
					            (centroids[j].lat - data[i].location.lat) +
								(centroids[j].lon - data[i].location.lon) *
								(centroids[j].lon - data[i].location.lon));
				if(data[i].dist > distance)
				{
					data[i].dist = distance;
					data[i].centroid = j;
					data[i].changed = true;
				}
			}
		}


		//calculate the mean of both lat & lon for each point associated with
		//each centroid
		for(i = 0; i < n_data_points; ++i)
		{
			//check if that data point changed centroids, if it did then 
			//increment n_changed
			if(data[i].changed)
			{
				n_changed++;
				data[i].changed = false;
			}
			means[data[i].centroid].lat += data[i].location.lat;
			means[data[i].centroid].lon += data[i].location.lon;
			//increment the record count for that centroid
			counts[data[i].centroid] += 1;
		}
		//move the centroid's coordinates to those means.
		for(i = 0; i < n_centroids; ++i)
		{
			centroids[i].lat = means[i].lat / counts[i];
			centroids[i].lon = means[i].lon / counts[i];
		}
		if(double(n_changed)/n_data_points > 0.01)
			keep_going = true;
		else
			keep_going = false;
		std::cout << n_changed << std::endl;
	}
	
	

	

	//end timing

	//output the total time elapsed as well as how many nodes were used.

	//output to a file the list of centroids and the points that were
	//closest to them. make this a csv file with the following format:
	//centroid index, record x coordinate, record y coordinate 
	//have only one record per line.

	//deallocate centroids array
	delete [] centroids;
	delete [] data;
	delete [] means;

	return 0;
}