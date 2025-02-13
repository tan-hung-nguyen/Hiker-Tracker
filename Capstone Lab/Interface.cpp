/*
	Nguyen, Tan Hung

	Fall 2024
	CS A250 - C++ 2

	Outdoor Adventures
*/

#include "Interface.h"

#include <iostream>
#include <iomanip>

using namespace std;

void displayMenu()
{
	for (int i = 0; i < 51; ++i)
	{
		cout << '*';
	}

	cout << "\n\t\tHIKING IN THE US" << endl;

	for (int i = 0; i < 51; ++i)
	{
		cout << '*';
	}

	cout << "\n\n\t 1. Browse by location" << endl
		<< "\t 2. Browse by duration" << endl
		<< "\t 3. Browse by difficulty" << endl
		<< "\t 4. Browse by price" << endl
		<< "\t 5. Make a reservation" << endl
		<< "\t 6. View reservation" << endl
		<< "\t 7. Cancel reservation" << endl
		<< "\t 8. Exit" << endl;

}

void processReservation(const HikeList& hikeList, 
						MemberList& memberList,	
						Reservations& reservation)
{	
	int choice = 0;
	while(choice != 8)
	{
		cout << "\nPlease make a selection: ";
		cin >> choice;
		cout << endl;
		if (choice == 1)
		{
			chooseByLocation(hikeList, memberList, reservation);
			system("Pause");
			cout << endl;
			displayMenu();
			
		}
		else if (choice == 2)
		{
			chooseByDuration(hikeList, memberList, reservation);
			system("Pause");
			cout << endl;
			displayMenu();
		}
		else if (choice == 3)
		{
			chooseByDufficulty(hikeList, memberList, reservation);
			system("Pause");
			cout << endl;
			displayMenu();
		}
		else if (choice == 4)
		{
			chooseByPrice(hikeList, memberList, reservation);
			system("Pause");
			cout << endl;
			displayMenu();
		}
		else if (choice == 5)
		{
			makeReservation(hikeList, memberList, reservation);
			system("Pause");
			cout << endl;
			displayMenu();
		}
		else if (choice == 6)
		{
			viewReservation(hikeList, memberList, reservation);
			system("Pause");
			cout << endl;
			displayMenu();
		}
		else if (choice == 7)
		{
			cancelReservation(hikeList, memberList, reservation);
			system("Pause");
			cout << endl;
			displayMenu();
		}

	}
	
	cout << "Thank you for visiting!" << endl << endl;
}

void chooseByLocation(const HikeList& hikeList, MemberList& memberList,
											Reservations& reservation)
{
	hikeList.printAllLocation();
	cout << "\nChoose a location: ";
	string location;
	cin >> location;
	cout << endl;

	hikeList.printByLocation(location);
	askToReserve(hikeList, memberList, reservation);
}

void chooseByDuration(const HikeList& hikeList, MemberList& memberList,
										Reservations& reservation)
{
	cout << "\t(days)\n";
	hikeList.printByDuration();

	cout << "\nHow many days are you considering? ";
	int days = 0;
	cin >> days;
	cout << endl;

	hikeList.printByDuration(days);
	askToReserve(hikeList, memberList, reservation);
}

void chooseByDufficulty(const HikeList& hikeList, MemberList& memberList,
												Reservations& reservation)
{
	cout << "Choose difficulty level: \n\n"
		<< "\te. easy\n"
		<< "\tm. moderate\n"
		<< "\ts. strenous\n" << endl;
	cout << "Your choice: ";
	char difficulty = 'e';
	cin >> difficulty;

	cout << "\n \t(difficulty level)\n";
	hikeList.printByDifficulty(difficulty);
	cout << endl;

	askToReserve(hikeList, memberList, reservation);
}

void chooseByPrice(const HikeList& hikeList, MemberList& memberList,
										Reservations& reservation)
{
	hikeList.printByPrice();
	cout << endl;
	askToReserve(hikeList, memberList, reservation);
}

int askIfMember(MemberList& memberList)
{
	cout << "Are you a member? (y/n) ";
	char response = 'y';
	cin >> response;
	cout << endl;

	if (response == 'y')
	{
		cout << "What is your member ID number? ";
		int idNumber = 0;
		cin >> idNumber;

		cout << "\nWhat is your last name? ";
		string lastName;
		cin >> lastName;
		cout << endl;

		memberList.printMember(idNumber, lastName);

		return idNumber;
	}
	else
	{
		return addNewMember(memberList);
	}

}

int addNewMember(MemberList& memberList)
{

	cout << "\tLet's add you to the member list! \n"
		<< "\t\tWhat is your first name? ";
	string firstName;
	cin >> firstName;

	cout << "\t\tWhat is your last name? ";
	string lastName;
	cin >> lastName;
	cout << endl;

	memberList.addMember(firstName, lastName);

	cout << "\tWelcome to the club!\n"
		<< "\t\tYour member ID number is: " << memberList.getLastID()
		<< endl << endl;
	return memberList.getLastID();

}

void makeReservation(const HikeList& hikeList, MemberList& memberList,
										Reservations& reservation)
{
	int memberID = askIfMember(memberList);

	cout << "Which hike would you like to reserve (hike name)? ";
	string hike;
	cin >> hike;
	cout << endl;

	hikeList.printByHikeName(hike);
	
	double discounted = hikeList.getPrice(hike) - 
						(memberList.getPoints(memberID) / 100);
	if (discounted != hikeList.getPrice(hike))
	{
		cout << "\tDiscounted price using points: $" << fixed
			<< setprecision(2) << discounted << endl << endl;
	}
	int reservationNumber = reservation.addReservation(memberID, hike);
	cout << "\tBefore proceeding, please make a note of your "
		<< "reservation number.\n"
		<< "\t  Reservation #: " << reservationNumber;

	cout << "\n\n( *** Will continue to scheduling and payment. *** )"
		<< endl << endl;
}

void viewReservation(const HikeList& hikeList, MemberList& memberList,
										Reservations& reservation)
{
	cout << "Enter reservation #: ";
	int reservationNum = 0;
	cin >> reservationNum;
	cout << endl;

	reservation.printReservation(reservationNum, hikeList, memberList);
}

void cancelReservation(const HikeList& hikeList, MemberList& memberList,
											Reservations& reservation)
{
	cout << "Enter reservation #: ";
	int reservationNum = 0;
	cin >> reservationNum;
	cout << endl;
	reservation.printReservation(reservationNum, hikeList, memberList);

	cout << "Are you sure you want to cancel this reservation? (y/n) ";
	char response = 'y';
	cin >> response;
	cout << endl;

	if (response == 'y')
	{
		reservation.cancelReservation(reservationNum);
		cout << "Reservation #" << reservationNum
			<< " has been canceled.\n\n";
	}
}

void askToReserve(const HikeList& hikeList, MemberList& memberList,
									Reservations& reservation)
{
	cout << "Would you like to make a reservation? (y/n) ";
	char response = 'y';
	cin >> response;
	cout << endl; 

	if (response == 'y')
	{
		makeReservation(hikeList, memberList, reservation);
	}
}