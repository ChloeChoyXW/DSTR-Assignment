#include <iostream>
#include <sstream>
#include <ctime>
#include <chrono>

using namespace std;

string getCurrentDate()
{
	time_t Date;
	struct tm DateInfo;
	char buffer[80];
	time(&Date);
	localtime_s(&DateInfo, &Date);
	strftime(buffer, sizeof(buffer), "%Y-%m-%d", &DateInfo);
	string currentDate(buffer);
	return currentDate;
}

string getCurrentTime()
{
	time_t Time;
	struct tm timeInfo;
	char buffer[80];
	time(&Time);
	localtime_s(&timeInfo, &Time);
	strftime(buffer, sizeof(buffer), "%H:%M:%S", &timeInfo);
	string currentTime(buffer);
	return currentTime;
}

tm stringToTm(string dateTime,int x)
{
	tm timeStruct{};
	istringstream iss(dateTime);
	if (x == 1) 
	{
		iss >> get_time(&timeStruct, "%Y-%m-%d");
	}
	else 
	{
		iss >> get_time(&timeStruct, "%H:%M:%S");
	}
	return timeStruct;
}

string tmToString(tm dateTime, int x)
{
	tm timeStruct{};
	char buffer[20];
	if (x == 1)
	{
		strftime(buffer, sizeof(buffer), "%Y-%m-%d", &timeStruct);
		string date(buffer);
		return date;
	}
	else
	{
		strftime(buffer, sizeof(buffer), "%H:%M:%S", &timeStruct);
		string time(buffer);
		return time;
	}
}
