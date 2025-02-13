/*
	Nguyen, Tan Hung

	Fall 2024
	CS A250 - C++ 2

	Outdoor Adventures
*/

#ifndef MEMBER_H
#define MEMBER_H	

#include <string>

class Member
{
public:
	inline Member(const std::string& aFirstName,
					const std::string& aLastName) :
					id(0), points(0),
					firstName(aFirstName), lastName(aLastName) {}

	void addPoints(int morePoints);
	void setID(int newID);

	int getID() const;
	std::string getLastName() const;
	int getPoints() const;

	void printMember() const;

	bool operator<(const Member& rightMemberObj) const;

private:
	int id;
	std::string firstName;
	std::string lastName;
	int points;
};
#endif // !MEMBER_H
