/*
	Nguyen, Tan Hung

	Fall 2024
	CS A250 - C++ 2

	Outdoor Adventures
*/

#include "MemberList.h"
#include "Reservations.h"

#include <iostream>

using namespace std;

MemberList::MemberList(const MemberList& otherMemberListObj)
{
	memberList = new set<Member>(*otherMemberListObj.memberList);
}

MemberList& MemberList::operator=(const MemberList& otherMemberListObj)
{
	if (this == &otherMemberListObj)
	{
		cerr << "Attempted assignment to itself." << endl;
	}
	else
	{
		*memberList = set<Member>(*otherMemberListObj.memberList);
	}
	return *this;
}

Reservations::Reservations(const Reservations& otherReservObj)
{
	if (otherReservObj.first == nullptr)
	{
		first = last = nullptr;
		count = 0;
	}
	else
	{
		first = last = nullptr;
		count = 0;
		Node* current = otherReservObj.first;
		while (current != nullptr)
		{
			addReservation(current->getMemberID(),
								current->getHikeName());
			current = current->getNext();
		}
	}
}

Reservations& Reservations::operator=(const Reservations& otherReservObj)	
{
	if (this == &otherReservObj)
	{
		cerr << "Attempted assignment to itself." << endl;					            
	}
	else
	{
		if (otherReservObj.first == nullptr)
		{
			clearList();
		}
		else if (count == 0)
		{
			copyCallingObjIsEmpty(otherReservObj);
		}
		else if (count == otherReservObj.count)
		{
			copyObjectsSameLength(otherReservObj);
		}
		else if (count > otherReservObj.count)
		{
			copyCallingObjLonger(otherReservObj);
		}
		else
		{
			copyCallingObjShorter(otherReservObj);
		}
	}
	return *this;
}

void Reservations::copyCallingObjIsEmpty(const Reservations& otherReservObj)	
{
	first = last = nullptr;
	count = 0;
	Node* current = otherReservObj.first;										
	while (current != nullptr)
	{
		addReservation(current->getMemberID(), current->getHikeName());		      
		current = current->getNext();
	}
}

void Reservations::copyObjectsSameLength(const Reservations& otherReservObj)	
{
	Node* currentObj = first;
	Node* currentOtherObj = otherReservObj.first;
	while (currentObj != nullptr)
	{
		currentObj->setReservationNo(currentOtherObj->getReservation());
		currentObj->setMemberID(currentOtherObj->getMemberID());
		currentObj->setHikeName(currentOtherObj->getHikeName());

		currentObj = currentObj->getNext();
		currentOtherObj = currentOtherObj->getNext();
	}
}

void Reservations::copyCallingObjLonger(const Reservations& otherReservObj)	
{
	Node* currentObj = first;
	Node* currentOtherObj = otherReservObj.first;
	while (currentOtherObj != nullptr)
	{
		currentObj->setReservationNo(currentOtherObj->getReservation());
		currentObj->setMemberID(currentOtherObj->getMemberID());
		currentObj->setHikeName(currentOtherObj->getHikeName());

		currentObj = currentObj->getNext();
		currentOtherObj = currentOtherObj->getNext();
	}

	while (currentObj != last)
	{
		last = last->getPrev();
		delete last->getNext();
		last->setNext(nullptr);
		count--;
	}

	count--;
	currentObj->getPrev()->setNext(nullptr);
	delete currentObj;
	currentObj = nullptr;
}

void Reservations::copyCallingObjShorter(const Reservations& otherReservObj)	
{
	Node* currentObj = first;
	Node* currentOtherObj = otherReservObj.first;							   
	while (currentObj != nullptr)
	{
		currentObj->setReservationNo(currentOtherObj->getReservation());
		currentObj->setMemberID(currentOtherObj->getMemberID());
		currentObj->setHikeName(currentOtherObj->getHikeName());

		currentObj = currentObj->getNext();
		currentOtherObj = currentOtherObj->getNext();
	}

	while (currentOtherObj != nullptr)
	{
		last = new Node(currentOtherObj->getMemberID(), 
						currentOtherObj->getHikeName(), last, nullptr);
		last->setReservationNo(currentOtherObj->getReservation());
		last->getPrev()->setNext(last);
		count++;
		currentOtherObj = currentOtherObj->getNext();
	}
}