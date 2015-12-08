// csv_read_test.cpp

#include "clustering.h"

void printRecord(record r)
{
	std::cout << r.location.lat << " " << r.location.lon << std::endl;
}

int main(int argc, char const *argv[])
{
	std::string file = argv[1];
	record* array;
	int count;

	if (readCSV(file, array, count))
	{
		for (int i = 0; i < count; ++i)
		{
			printRecord(array[i]);
		}
		std::cout << "success" << std::endl;
	}
	else
	{
		std::cout << "failure" << std::endl;
	}

	return 0;
}
