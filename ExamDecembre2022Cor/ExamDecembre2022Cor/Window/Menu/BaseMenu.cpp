#include "BaseMenu.h"
#include "../Control/WindowControl.h"
#include "../Control/TextField/TextFieldControl.h"
#include "../Control/Calendar/CalendarControl.h"
#include "../Window.h"

#pragma region constructor
BaseMenu::BaseMenu(Window* _owner, const char* _name) : super()
{
	owner = _owner;
	name = _name;
}

BaseMenu::BaseMenu(const BaseMenu& _copy) : super(_copy)
{
	owner = _copy.owner;
	name = _copy.name;
}

#pragma endregion constructor
#pragma region methods
bool BaseMenu::IsInitialized() const
{
	return isInitialized;
}
void BaseMenu::Open()
{
	if (!isInitialized) return; 
	for (WindowControl* _control : controls)
		_control->Show(); 
}
void BaseMenu::Close()
{
	if (!isInitialized) return;
	for (WindowControl* _control : controls)
		_control->Hide();
}
void BaseMenu::Initialize()
{
	std::string _str = name; 
	const int _width = (owner->Width() / 2) - (std::pow(_str.length() / 2, 2)); 
	const std::wstring _wName(_str.begin(), _str.end());
	CreateLabel(Rect(_width, 0, 255, 20), _wName.c_str()); 
}
std::string BaseMenu::Name()
{
	return name;
}
void BaseMenu::CreateButton(const Rect& _rect, const wchar_t* _text)
{
	ButtonControl* _button = new ButtonControl(currentControlID++, owner->WindowInstance(), _rect, _text);
	_button->Create();
	controls.push_back(_button);
}
void BaseMenu::CreateLabel(const Rect& _rect, const wchar_t* _text)
{
	LabelControl* _label = new LabelControl(currentControlID++, owner->WindowInstance(), _rect, _text);
	_label->Create();
	controls.push_back(_label); 
}
void BaseMenu::CreateTextField(const Rect& _rect, const wchar_t* _defaultText)
{
	TextFieldControl* _textField = new TextFieldControl(currentControlID++, owner -> WindowInstance(), _rect, _defaultText); 
	_textField->Create();
	controls.push_back(_textField);
}
CalendarControl* BaseMenu::CreateCalendar(const Rect& _rect)
{
	CalendarControl* _calendar = new CalendarControl(currentControlID++, owner->WindowInstance(), _rect);
	_calendar->Create(); 
	controls.push_back(_calendar);
	return _calendar;
}
#pragma endregion methods