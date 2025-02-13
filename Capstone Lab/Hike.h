/*
	Nguyen, Tan Hung
	
	Fall 2024
	CS A250 - C++ 2

	Outdoor Adventures
*/

#ifndef HIKE_H
#define HIKE_H

#include <iostream>
#include <string>

class Hike
{
	friend std::ostream& operator<<(std::ostream& out, const Hike& aHike);
public:
	inline Hike(const std::string& theLocation,
		const std::string& theHikeName, int theDuration, 
		char theDifficulty) :
		location(theLocation), hikeName(theHikeName),
		duration(theDuration), difficulty(theDifficulty) {}

	std::string getLocation() const;
	int getDuration() const;
	char getDifficulty() const;
	std::string getHikeName() const;

	bool operator<(const Hike& rightHikeObj) const;

private:
	std::string location;
	std::string hikeName;
	int duration;
	char difficulty;
};
#endif