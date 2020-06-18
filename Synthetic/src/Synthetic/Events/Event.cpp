#include "Event.h"

namespace syn {

	std::string Event::toString() const { return "Event"; }

	EventListener::EventListener() {
		listeners.push_back(this);
	}

	EventListener::~EventListener() {
		listeners.erase(
			std::remove(
				listeners.begin(),
				listeners.end(),
				this
			),
			listeners.end()
		);
	}

	bool EventListener::dispatch(Event& event) {
		for(auto &listener : listeners) {
			if(event.handled) break;
			event.handled = listener->onEvent(event);
		}
		return event.handled;
	}

	std::vector<EventListener*> EventListener::listeners;
}
