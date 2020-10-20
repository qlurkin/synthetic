#pragma once

namespace syn {
	class Event;

	class BaseListener {};

	template<class T>
	class Listener: public BaseListener {
		public:
			virtual bool on(T& event) = 0;
	};
}
