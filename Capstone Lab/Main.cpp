/*
	Nguyen, Tan Hung

	Fall 2024
	CS A250 - C++ 2

	Outdoor Adventures
*/

#include "Hike.h"
#include "Member.h"
#include "MemberList.h"
#include "HikeList.h"
#include "Reservations.h"
#include "MemberReader.h"
#include "HikeReader.h"
#include "ReservationReader.h"
#include "Interface.h"

#include <iostream>

using namespace std;

int main()
{
	MemberList memberList;
	getMemberData(memberList);
	HikeList hikeList;
	getHikeData(hikeList);
	Reservations reservations;
	getReservationData(reservations);
	displayMenu();
	processReservation(hikeList, memberList, reservations);

	system("Pause");
	return 0;
}