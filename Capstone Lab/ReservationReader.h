/*
	Nguyen, Tan Hung

	Fall 2024
	CS A250 - C++ 2

	Outdoor Adventures
*/

#include "Reservations.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const string RESERVATIONS_FILE = "reservations_database.txt";

void createReservationList(ifstream& infile, 
							Reservations& reservationList)
{
	int idNumber = 0;
	string hikeName;

	while (!infile.eof())
	{
		infile >> idNumber >> hikeName;
		reservationList.addReservation(idNumber, hikeName);
	}
}

void getReservationData(Reservations& reservationList)
{
	ifstream infile;

	infile.open(RESERVATIONS_FILE);

	if (!infile)
	{
		cerr << RESERVATIONS_FILE << " does not exist." << endl;
		exit(1); // terminates program
	}

	createReservationList(infile, reservationList);

	infile.close();
}


