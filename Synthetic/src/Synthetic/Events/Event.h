#pragma once
#include "pch.h"

#include "Synthetic/core.h"

#include "Listener.h"

namespace syn {
	class Event {
		public:
			Event() {}
			virtual ~Event() = default;

			bool handled = false;

			virtual std::string toString() const {
				return "Default Event";
			}

			virtual bool dispatch() {
				return Dispatcher::dispatch(*this);
			}
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.toString();
	}
}

#include "KeyEvent.h"
#include "MouseEvent.h"
#include "ApplicationEvent.h"
