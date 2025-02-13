/*
	Nguyen, Tan Hung

	Fall 2024
	CS A250 - C++ 2

	Outdoor Adventures
*/

#ifndef RESERVATIONS_H
#define RESERVATIONS_H

#include "HikeList.h"
#include "MemberList.h"

#include <string>

const int FIRST_RESERVATION_NUMBER = 5001;

class Node
{
public:
	inline Node() : reservationNo(0), memberID(0),
					prev(nullptr), next(nullptr) {}
	inline Node(int member, const std::string& aHike,
				Node* newPrev, Node* newNext) :
				reservationNo(0), memberID(member), hikeName(aHike),
				prev(newPrev), next(newNext) {}
	inline int getReservation() const { return reservationNo; }
	inline int getMemberID() const { return memberID; }
	inline const std::string& getHikeName() const { return hikeName; }
	inline Node* getPrev() const { return prev; }
	inline Node* getNext() const { return next; }
	inline void setReservationNo(int reservation)
					{ reservationNo = reservation; }
	inline void setMemberID(int member) { memberID = member; }
	inline void setHikeName(const std::string& aHike)
									{ hikeName = aHike; }
	inline void setPrev(Node* newPrev) { prev = newPrev; }
	inline void setNext(Node* newNext) { next = newNext; }
	inline ~Node() {}
private:
	int reservationNo;
	int memberID;
	std::string hikeName;
	Node* next;
	Node* prev;
};

class Reservations 
{
public:
	inline Reservations() : count(0), first(nullptr), last(nullptr) {}
	Reservations(const Reservations& otherReservObj);

	Reservations& operator=(const Reservations& otherReservObj);

	int addReservation(int memberID, const std::string& hikeName);

	void cancelReservation(int reservation);

	void printReservation(int reservation,const HikeList& hikeList,
								const MemberList& memberList) const;

	void clearList();
	~Reservations();

private:

	Node* findReservation(int reservation) const;

	void copyCallingObjIsEmpty(const Reservations& otherReservObj);
	void copyObjectsSameLength(const Reservations& otherReservObj);
	void copyCallingObjLonger(const Reservations& otherReservObj);
	void copyCallingObjShorter(const Reservations& otherReservObj);

	Node* first;
	Node* last;
	int count;
};
#endif // !RESERVATIONS_H
