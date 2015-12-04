/*
K-Means Clustering:
	1. Read data from file and store in container
	2. Partition data to be sent to nodes
	3. Send data to assigned nodes
	4. Place initial centroids
	5. Send centroids to all nodes
	Each node:
		6. Calculate distances and add up totals (distances to nearest centroid, number of points assigned to that centroid)
		7. Send total of distances & number of points for each centroid to root node
	Root node:
		8. Combine distance and point numbers to generate new centroid locations
		9. Send new centroid locations to all nodes
	Repeat steps 6 - 9 until stop condition met
*/

/*
Other parts of the program:
	Command line arguments: <number of nodes> <number of clusters>
	Need to determine what type of data structure to use for record container
	Partition data into n groups and send to nodes (n is the number of nodes)
	Calculate timings (should be done by root node only)
*/