/*
	Nguyen, Tan Hung

	Fall 2024
	CS A250 - C++ 2

	Outdoor Adventures
*/

#include "Reservations.h"

#include <iostream>
#include <iomanip>

using namespace std;

int Reservations::addReservation(int memberID, 
							const std::string& hikeName)
{
	if (count == 0)
	{
		first = new Node(memberID, hikeName, nullptr, nullptr);
		first->setReservationNo(FIRST_RESERVATION_NUMBER);
		last = first;
		++count;
	}
	else
	{
		last = new Node(memberID, hikeName, last, nullptr);
		last->getPrev()->setNext(last);
		last->setReservationNo(last->getPrev()->getReservation() + 1 );
		++count;
	}
	return last->getReservation();
}

void Reservations::cancelReservation(int reservation)
{
	Node* reservationPtr = findReservation(reservation);
	if (count == 1)
	{
		delete first;
		last = first = nullptr;
		count = 0;
	}
	else
	{
		if (reservationPtr == first)
		{
			first = reservationPtr->getNext();
			first->setPrev(nullptr);
			reservationPtr->setNext(nullptr);
			delete reservationPtr;
			reservationPtr = nullptr;
			count--;
		}
		else if (reservationPtr == last)
		{
			last = last->getPrev();
			last->setNext(nullptr);
			delete reservationPtr;
			reservationPtr = nullptr;
			count--;
		}
		else
		{
			reservationPtr->getPrev()->setNext(reservationPtr->getNext());
			reservationPtr->getNext()->setPrev(reservationPtr->getPrev());
			delete reservationPtr;
			reservationPtr = nullptr;
			--count;
		}
	}
}

void Reservations::printReservation(int reservation,
									const HikeList& hikeList,
									const MemberList& memberList) const
{
	Node* reservationPtr = findReservation(reservation);
	hikeList.printByHikeName(reservationPtr->getHikeName());

	int points = memberList.getPoints(reservationPtr->getMemberID());
	double price = hikeList.getPrice(reservationPtr->getHikeName());
	double discountedPrice = price - (points / 100);
	if (discountedPrice != price)
	{
		cout << "\tDiscounted price using points: $" << fixed
			<< setprecision(2) << discountedPrice << endl << endl;
	}
}

void Reservations::clearList()
{
	Node* temp = first;
	while (first != nullptr)
	{
		first = first->getNext();
		delete temp;
		temp = first;
	}

	last = nullptr;
	count = 0;
}

Reservations::~Reservations()
{
	if (first != nullptr)
		clearList();
}

Node* Reservations::findReservation(int reservation) const
{
	Node* current = first;
	while (current->getReservation() != reservation)
	{
		current = current->getNext();
	}
	return current;
}