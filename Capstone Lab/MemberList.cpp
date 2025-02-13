/*
	Nguyen, Tan Hung

	Fall 2024
	CS A250 - C++ 2

	Outdoor Adventures
*/

#include "MemberList.h"

#include <algorithm>
#include <iostream>

using namespace std;

void MemberList::addMember(const std::string& firstName,
							const std::string& lastName)
{
	if (memberList->empty())
	{
		Member aMember(firstName, lastName);
		aMember.setID(FIRST_ID);
		memberList->insert(aMember);
	}
	else
	{
		Member aMember(firstName, lastName);
		int size = static_cast<int>(memberList->size());
		aMember.setID(FIRST_ID + size);
		memberList->insert(aMember);
	}
}

void MemberList::addMember(const std::string& firstName,
					const std::string& lastName, int points)
{
	if (memberList->empty())
	{
		Member aMember(firstName, lastName);
		aMember.setID(FIRST_ID);
		aMember.addPoints(points);
		memberList->insert(aMember);
	}
	else
	{
		Member aMember(firstName, lastName);
		int size = static_cast<int>(memberList->size());
		aMember.setID(FIRST_ID + size);
		aMember.addPoints(points);
		memberList->insert(aMember);
	}
}

int MemberList::getLastID() const
{
	return memberList->rbegin()->getID();
}

int MemberList::getPoints(int memberID) const
{
	auto memberIter = find_if(memberList->begin(), memberList->end(),
		[memberID](Member person) {return person.getID() == memberID; });

	return memberIter->getPoints();
}

void MemberList::printMember(int memberID,
							const std::string& lastName) const
{
	auto memberIter = find_if(memberList->begin(), memberList->end(),
		[memberID](Member aMember){return aMember.getID() == memberID; });

		memberIter->printMember();
		cout << "\tMembership # " << memberIter->getID() << endl;
		cout << endl;

}

void MemberList::clearList()
{
	memberList->clear();
}

MemberList::~MemberList()
{
	delete memberList;
	memberList = nullptr;
}

