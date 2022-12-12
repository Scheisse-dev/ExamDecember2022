#pragma once
#include "../../Object/Object.h"

template<typename Res, typename... Args>
class Delegate : public Object
{
#pragma region f/p
private: 
	typedef Res(Object::* Function)(Args...);
	Function function = nullptr; 
	Object* instance = nullptr; 
#pragma endregion f/p
#pragma region constructor
public: 
	Delegate() = default; 
	Delegate(nullptr_t)
	{
		instance = nullptr;
		function = nullptr;
	}
#pragma endregion constructor 
#pragma region methods
public: 
	template<typename Class> 
	void SetDynamic(Class* _instance, Res(Class::* ptr)(Args...))
	{
		if constexpr (!std::is_base_of_v<Object, Class>)
			throw std::exception("[Delegate] => Class must be inherited of Object");
		instance = _instance; 
		function = reinterpret_cast<Function>(ptr); 
	}
	Res Invoke(Args... _args)
	{
		if (function == nullptr || instance == nullptr)
			throw std::exception("[Delegate] => function or instance is null !");
		return (instance->*function)(_args...); 
	}
#pragma endregion methods
#pragma region operator
public: 
	void operator=(nullptr_t)
	{
		instance = function = nullptr; 
	}
#pragma endregion operator
};
