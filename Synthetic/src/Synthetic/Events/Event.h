#pragma once

#include "Synthetic/core.h"

namespace syn {
	class SYN_API Event {
		public:
			virtual ~Event() = default;

			bool handled = false;

			virtual std::string toString() const;
	};
}

#include "Listener.h"
