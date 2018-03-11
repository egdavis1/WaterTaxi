#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
	ifstream inFile;
	ofstream outFile;
	
	int numTrip = 0;
	double num = 0, distance, totalDistance = 0, numR = 0, disE = 0, cost = 0,
		   totalCost = 0, longestTrip = 0, lowestCost = 0;
	const double DISTANCE_RATE = 2.70, TRIP_RATE = 11.00;
	
	bool returnT = true;
	
	inFile.open("taxi.txt");
	outFile.open("taxi_info.txt");

	//Write headings to outFile
	outFile << "Trip\tReturn\tStops\tDistance\tCost\t\tCumlative\tCumatlive\n";
	outFile << "\t\t\t\t\t\t\tDistance\tCost\n";
	
	for (int x = 0; x < 78; x ++)
	{
		inFile >> returnT;
		inFile >> numTrip;
			
		double tripx[numTrip + 1], tripy[numTrip + 1];
		tripx[0] = 0;
		tripy[0] = 0;
		
		for (int y = 1; y < numTrip + 1; y ++)
		{
			inFile >> tripx[y];
			inFile >> tripy[y];
		}
	
		distance = 0;
		
		//Calculate total distance of trip
		for (int z = 0; z < numTrip; z ++)
		{
			distance = distance + sqrt((pow(tripx[z+1] - tripx[z], 2)) + (pow(tripy[z+1] - tripy[z], 2)));
			disE = sqrt((pow(tripx[z+1] - tripx[z], 2)) + (pow(tripy[z+1] - tripy[z], 2)));	
		}

	
		if (returnT == 1)
		{
			distance = distance + sqrt(pow(tripx[numTrip], 2) + pow(tripy[numTrip], 2));		
		}
		
		cost = distance * DISTANCE_RATE + numTrip * TRIP_RATE;
		totalCost += cost;
		
		totalDistance += distance;
		
		//Write information to the outFile
		if (x == 0)
		{
			lowestCost = cost;
		}
		else if (cost < lowestCost)
		{
			lowestCost = cost;
		}
		
		if (distance > longestTrip)
		{
			longestTrip = distance;
		}
		
		if (x < 5 || (x+1)%10 == 0)
		{
			outFile << x+1 << "\t";
			outFile << returnT << "\t" << numTrip << "\t";
			outFile << distance << "\t\t" << cost << "\t\t" << totalDistance << "\t\t" << totalCost << "\n";
		}
	}
	
	outFile << "\nLowest cost: " << lowestCost << "\tLongest Trip: " << longestTrip << endl;
	
	//Close the files
	outFile.close();
	inFile.close();
	
	return 0;
}

