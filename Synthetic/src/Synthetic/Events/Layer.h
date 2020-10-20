#pragma once

#include "Synthetic/core.h"
#include "Listener.h"

#include <typeinfo>
#include <typeindex>

namespace syn {

	class Layer {
		public:
			Layer(const std::string& name = "Layer");
			inline const std::string& getName() const { return debugName; }

			template<class T>
			void add(Listener<T>* listener) {
				listeners[std::type_index(typeid(T))].push_back(listener);
			}

			template<class T>
			void remove(Listener<T>* listener) {
				std::vector<BaseListener*> theListeners = listeners[std::type_index(typeid(T))];
						
				theListeners.erase(
					std::remove(
						theListeners.begin(),
						theListeners.end(),
						listener
					),
					theListeners.end()
				);
			}

			template<class T>
			bool dispatch(T& event) {
				for(BaseListener* listener: listeners[std::type_index(typeid(T))]) {
					Listener<T>* theListener = (Listener<T>*) listener;
					if (theListener->on(event)) {
						event.handled = true;
					}
				}

				return event.handled;
			}

		private:
			std::string debugName;
			std::unordered_map <std::type_index, std::vector<BaseListener*>> listeners;
	};

}