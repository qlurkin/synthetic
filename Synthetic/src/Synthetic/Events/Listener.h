#pragma once

namespace syn {
	template <class T>
	class Listener {
		friend class Dispatcher;

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

		private:
			static std::vector<Listener<T>*> listeners;

	};

	template <class T>
	std::vector<Listener<T>*> Listener<T>::listeners;

	class Dispatcher {
		public:
			template <class T>
			static bool dispatch(T& event) {
				for(auto &listener : Listener<T>::listeners) {
					if(event.handled) break;
					event.handled = listener->on(event);
				}
				return event.handled;
			}
	};
}
