/*
	Nguyen, Tan Hung

	Fall 2024
	CS A250 - C++ 2

	Outdoor Adventures
*/

#include "HikeList.h"

#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;

void HikeList::addHike(const Hike& hike, double price)
{
	hikeList.insert(make_pair(hike, price));
}

void HikeList::addHike(const string& location, const string& hikeName,
	int duration, char difficulty, double price)
{
	Hike aHike(location, hikeName, duration, difficulty);
	hikeList.insert(make_pair(aHike, price));
}

double HikeList::getPrice(const string& hikeName) const
{
	auto hikePriceIter = find_if(hikeList.begin(), hikeList.end(),
	[hikeName](auto& hike){return hike.first.getHikeName() == hikeName;});
	return hikePriceIter->second;
}

void HikeList::printAllLocation() const
{
	auto locationIter = hikeList.begin();
	bool done = false;
	while (!done)
	{
		cout << "\t" << locationIter->first.getLocation() << endl;
		locationIter = hikeList.upper_bound(locationIter->first);

		if (locationIter == hikeList.end())
		{
			done = true;
		}
	}
}

void HikeList::printByLocation(const std::string& location) const
{
	bool done = false;
	auto locationIter = find_if(hikeList.begin(), hikeList.end(),
	[location](auto& hike){return hike.first.getLocation() == location;});
	while (!done && locationIter->first.getLocation() == location)
	{
		cout << locationIter->first
			<< "\n\t  Price (per person): $ " << fixed << setprecision(2)
			<< locationIter->second << endl;
		locationIter++;
		cout << endl;
		if (locationIter == hikeList.end())
		{
			done = true;
		}
	}
}

void HikeList::printByDuration() const
{
	multimap<int, string> tempMap;
	for (const auto& hike : hikeList)
	{
		string detail = hike.first.getHikeName() + ", "
							+ hike.first.getLocation();
		tempMap.insert(make_pair(hike.first.getDuration(), detail));
		
	}

	for (const auto& duration : tempMap)
	{
		cout << "\t(" << duration.first << ") "
			<< duration.second << endl;
	}
}

void HikeList::printByDuration(int days) const
{
	for (const auto& hike : hikeList)
	{
		if (hike.first.getDuration() == days)
		{
			cout << hike.first << endl << endl;
		}
	}
}

void HikeList::printByDifficulty(char difficulty) const
{
	for (const auto& hike : hikeList)
	{
		if (hike.first.getDifficulty() == difficulty)
		{
			cout << "\t(" << difficulty << ") " 
				<< hike.first.getHikeName()
				<< ", " << hike.first.getLocation() << endl;
		}
	}
}

void HikeList::printByPrice() const
{
	multimap<double, pair<string, string>> tempMap;
	for (const auto& price : hikeList)
	{
		tempMap.emplace(price.second, 
		make_pair(price.first.getLocation(), price.first.getHikeName()));
	}

	for (const auto& location : tempMap)
	{
		cout << "\t$" << fixed << setprecision(2) << setw(8) 
			<< location.first << " - " << location.second.first << " (" 
			<< location.second.second << ")" << endl;
	}
}

void HikeList::printByHikeName(const std::string& hikeName) const
{
	auto hikeNameIter = find_if(hikeList.begin(), hikeList.end(),
	[hikeName](auto& hike){return hike.first.getHikeName() == hikeName;});
	cout << hikeNameIter->first << endl
		<< "\t  $" << fixed << setprecision(2)
		<< hikeNameIter->second << endl;
	cout << endl;
}

void HikeList::clearList()
{
	hikeList.clear();
}