/*
	Nguyen, Tan Hung

	Fall 2024
	CS A250 - C++ 2

	Outdoor Adventures
*/

#include "Hike.h"

using namespace std;

ostream& operator<<(ostream& out, const Hike& aHike)
{
	out << "\t" << aHike.hikeName << " ("
		<< aHike.location << ")\n"
		<< "\t  " << "Difficulty: ";

	if (aHike.difficulty == 'e')
		out << "easy\n";
	else if (aHike.difficulty == 'm')
		out << "moderate\n";
	else
		out << "strenuous\n";

	out << "\t  " << "Duration: " << aHike.duration << " day(s)";

	return out;
}

string Hike::getLocation() const
{
	return location;
}

int Hike::getDuration() const
{
	return duration;
}

char Hike::getDifficulty() const
{
	return difficulty;
}

string Hike::getHikeName() const
{
	return hikeName;
}

bool Hike::operator<(const Hike& rightHikeObj) const
{
	return location < rightHikeObj.location;
}