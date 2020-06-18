#pragma once

#include <string>
#include <vector>
#include <algorithm>

#include <Synthetic/core.h>

namespace syn {
	class SYN_API Event {
		public:
			virtual ~Event() = default;

			bool handled = false;

			virtual std::string toString() const;
	};

	class SYN_API EventListener {
		public:
			EventListener();
			virtual ~EventListener();
			virtual bool onEvent(Event& event) = 0;
			static bool dispatch(Event& event);

		private:
			static std::vector<EventListener*> listeners;
	};
}

#include "KeyEvent.h"
