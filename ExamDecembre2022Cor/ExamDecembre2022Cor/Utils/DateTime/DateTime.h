#pragma once
#include "../../Object/Object.h"
#include <Windows.h>


class DateTime: public Object
{
	DECLARE_CLASS_INFO(Object)
#pragma region f/p
private:
	int day = 0; 
	int month = 0;
	int year = 0; 
	int hour = 0; 
	int minute = 0;
	int second = 0;
public:
	static const DateTime Now; 
#pragma endregion f/p
#pragma region constructor
public:
	DateTime() = default; 
	DateTime(int _day, int _month, int _year, int _hour, int _minute, int _second);
	DateTime(const SYSTEMTIME& _time);
	DateTime(const DateTime& _copy); 
#pragma endregion constructor
#pragma region methods
private:
	static DateTime NowInternal();
public:
	SYSTEMTIME ToSystemTime() const;
#pragma endregion methods
#pragma region override 
public: 
	std::string ToString() const override;
#pragma endregion override 
};