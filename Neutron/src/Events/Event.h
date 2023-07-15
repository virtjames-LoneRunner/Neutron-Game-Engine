#pragma once

#include "Neutron/Core.h"

namespace Neutron {

	// This Event System is currently blocking, which means that it will be executed once
	// triggered.

	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory {
		None = 0,
		EventCategoryApplication	= BIT(0), // 00000001  Using Bitwise Operations to determine 
		EventCategoryInput			= BIT(1), // 00000010  if a category belongs with the other
		EventCategoryKeyboard		= BIT(2), // 00000100  by determining if there are any 1's left
		EventCategoryMouse			= BIT(3), // 00001000  during evaluation
		EventCategoryMouseButton	= BIT(4), // 00010000  Ex: ( 00010000 | 000010000 ) => 00011000 => CHECK IF: (0011000 & CATEGORY: 00100000)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
							   virtual EventType GetEventType() const override { return GetStaticType(); }\
							   virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class Event 
	{
	public:
		virtual ~Event() = default;

		bool Handled = false;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }
		
		bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category; // Bitwise &
		}
	};

	class EventDispatcher
	{
	public:
		EventDispatcher(Event& event)
			: m_Event(event) {}

		// F will be deduced by the compiler
		template<typename T, typename F>
		bool Dispatch(const F& func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.Handled |= func(static_cast<T&>(m_Event));
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}

