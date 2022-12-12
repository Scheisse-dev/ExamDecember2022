#include "CalendarControl.h"
#include <CommCtrl.h>
#pragma region constructor
CalendarControl::CalendarControl(int _controlID, HWND _owner, const Rect& _rect) : super(_controlID, _owner, _rect)
{
}

CalendarControl::CalendarControl(const CalendarControl& _copy) : super (_copy)
{
}
#pragma endregion constructor
#pragma region methods
void CalendarControl::SetMaxSelected(UINT _value)
{
	if (!isInitialized) return;
	MonthCal_SetMaxSelCount(instance, _value);
}
#pragma endregion methods

#pragma region override
HWND CalendarControl::Create()
{
	instance = CreateWindowEx(0, MONTHCAL_CLASS, L"", WS_BORDER | WS_CHILD | WS_VISIBLE | MCS_DAYSTATE | MCS_NOTODAY | MCS_MULTISELECT, 
		rect.X(), rect.Y(), rect.Width(), rect.Height(), owner, (HMENU)controlID, ownerInstance, nullptr);
	RECT _minRect = {};
	MonthCal_GetMinReqRect(instance, &_minRect);
	SetWindowPos(instance, NULL, rect.X(), rect.Y(), _minRect.right, _minRect.bottom, SWP_NOZORDER);
	/*Set Date Time*/
	SYSTEMTIME* _times = new SYSTEMTIME[2];
	GetSystemTime(&_times[0]);
	MonthCal_SetRange(instance, GDTR_MIN, &_times[0]);
	/*---------------*/
	MonthCal_SetCurrentView(instance, MCMV_MONTH);
	if (instance != NULL)
	{
		isInitialized = true; 
		Show();
	}
	return instance; 
}
#pragma endregion override