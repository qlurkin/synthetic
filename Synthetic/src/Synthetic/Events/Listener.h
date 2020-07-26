#pragma once

#include <typeinfo>
#include <typeindex>

namespace syn {
	class Event;
	
	class BaseListener {
		public:
			virtual bool process(Event& event) = 0;
	};

	template <class T>
	class Listener : public BaseListener {
		friend class Dispatcher;

		public:
			Listener() {
				Dispatcher::subscribe(std::type_index(typeid(T)), *this);
			}

			virtual ~Listener() {
				Dispatcher::unsubscribe(std::type_index(typeid(T)), *this);
			}

			bool process(Event& event) {
				T& typedEvent = (T&) event;
				return on(typedEvent);
			}

			virtual bool on(T& event) = 0;
	};

	class Dispatcher {
		public:
			Dispatcher();
			~Dispatcher();

			static void subscribe(std::type_index type, BaseListener& listener);
			static void unsubscribe(std::type_index type, BaseListener& listener);

			template <class T>
			static bool dispatch(T& event) {
				std::vector<BaseListener*> L = listeners[std::type_index(typeid(T))];

				for(BaseListener* listener : L) {
					if(event.handled) break;
					event.handled = listener->process(event);
				}
				return event.handled;
			}

		private:
			static std::unordered_map <std::type_index, std::vector<BaseListener*>> listeners;
	};
}
