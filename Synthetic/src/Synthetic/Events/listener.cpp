#include "pch.h"
#include "Listener.h"

namespace syn {

	Dispatcher::Dispatcher() {

	}

	Dispatcher::~Dispatcher() {

	}
	
	void Dispatcher::subscribe(std::type_index type, BaseListener& listener) {
		
		listeners[type].push_back(&listener);
	}

	void Dispatcher::unsubscribe(std::type_index type, BaseListener& listener) {
		std::vector<BaseListener*> L = listeners[type];

		L.erase(
			std::remove(
				L.begin(),
				L.end(),
				&listener
			),
			L.end()
		);
	}

	std::unordered_map <std::type_index, std::vector<BaseListener*>> Dispatcher::listeners;
}
