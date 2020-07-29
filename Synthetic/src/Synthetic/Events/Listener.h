#pragma once

#include <typeinfo>
#include <typeindex>

namespace syn {
	class Event;

	class BaseListener {};

	template <class T>
	class Listener : public BaseListener {
		public:
			Listener() {
				listeners.push_back(this);
			}

			virtual ~Listener() {
				listeners.erase(
					std::remove(
						listeners.begin(),
						listeners.end(),
						this
					),
					listeners.end()
				);
			}

			virtual bool on(T& event) = 0;
		
			static bool dispatch(T& event) {
				for(Listener<T>* listener: listeners) {
					if(event.handled) break;
					event.handled = listener->on(event);
				}

				return event.handled;
			}

		private:
			static std::vector<Listener<T>*> listeners;
	};

	template<class T>
	std::vector<Listener<T>*> Listener<T>::listeners;
}
