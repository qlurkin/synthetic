#pragma once

#include <typeinfo>
#include <typeindex>

namespace syn {
	class Event;

	class BaseListener {};

	template<class ... N>
	class Listener: public BaseListener {
		public:
			virtual bool process(Event& event) = 0;
			
			template<class T>
			static bool dispatch(T& event) {
				for(Listener<>* listener: allListeners[std::type_index(typeid(T))]) {
					if(event.handled) break;
					event.handled = listener->process(event);
				}

				return event.handled;
			}
		protected:
			static std::unordered_map <std::type_index, std::vector<Listener<>*>> allListeners;
	};

	template<class T, class ... Rest>
	class Listener<T, Rest...>: public Listener<Rest...> {
		public:
			Listener() {
				allListeners[std::type_index(typeid(T))].push_back(this);
			}

			virtual ~Listener() {
				std::vector<Listener<>*> listeners = allListeners[std::type_index(typeid(T))];
				
				listeners.erase(
					std::remove(
						listeners.begin(),
						listeners.end(),
						this
					),
					listeners.end()
				);
			}

			virtual bool process(Event& event) {
				T& typedEvent = (T&) event;
				return on(typedEvent);
			}

			virtual bool on(T& event) = 0;

		private:
			static std::vector<Listener<T, Rest...>*> listeners;
	};

	template<class T, class ... Rest>
	std::vector<Listener<T, Rest...>*> Listener<T, Rest...>::listeners;
}
