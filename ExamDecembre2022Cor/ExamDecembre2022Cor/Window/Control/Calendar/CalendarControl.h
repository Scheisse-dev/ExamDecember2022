#pragma once
#include "../WindowControl.h"
#include "../../../Utils/DateTime/DateTime.h"
#include <CommCtrl.h>
#include <map>
class DateTime;

class CalendarControl : public WindowControl
{

	DECLARE_CLASS_INFO(WindowControl)
#pragma region f/p
public:
	static inline std::map<int, CalendarControl*> calendars = std::map<int, CalendarControl*>();
private: 
	DateTime arrivedDate = DateTime(); 
	DateTime departureDate = DateTime();

#pragma endregion f/p
#pragma region constructor
public: 
	CalendarControl() = default; 
	CalendarControl(int _controlID, HWND _owner, const Rect& _rect); 
	CalendarControl(const CalendarControl& _copy); 
#pragma endregion constructor
#pragma region methods
public: 
	void SetMaxSelected(UINT _value);
	void SetValue(const DateTime& _a, const DateTime& _b);
	void OnChoice(LPNMSELCHANGE _value); 
	DateTime ArrivedDate() const; 
	DateTime DepartureDate() const;
	void SetInteract(bool _bool);
#pragma endregion methods
#pragma region override
public:
	HWND Create() override;
#pragma region override
};

