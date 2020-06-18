#include "KeyEvent.h"

#include <sstream>

namespace syn {
	KeyEvent::KeyEvent(int keyCode) : keyCode(keyCode) {}

	std::string KeyEvent::toString() const {
		std::stringstream ss;
		ss << "KeyEvent: " << keyCode;
		return ss.str();
	};


	KeyEventListener::KeyEventListener() {
		listeners.push_back(this);
	}

	KeyEventListener::~KeyEventListener() {
		listeners.erase(
			std::remove(
				listeners.begin(),
				listeners.end(),
				this
			),
			listeners.end()
		);
	}

	bool KeyEventListener::dispatch(KeyEvent& event) {
		for(auto &listener : listeners) {
			if(event.handled) break;
			event.handled = listener->onKeyEvent(event);
		}
		event.handled = EventListener::dispatch(event);
		return event.handled;
	}

	std::vector<KeyEventListener*> KeyEventListener::listeners;

	KeyPressedEvent::KeyPressedEvent(int keyCode) : KeyEvent(keyCode) {}

	std::string KeyPressedEvent::toString() const {
		std::stringstream ss;
		ss << "KeyPressedEvent: " << keyCode;
		return ss.str();
	};

	KeyPressedEventListener::KeyPressedEventListener() {
		listeners.push_back(this);
	}

	KeyPressedEventListener::~KeyPressedEventListener() {
		listeners.erase(
			std::remove(
				listeners.begin(),
				listeners.end(),
				this
			),
			listeners.end()
		);
	}

	bool KeyPressedEventListener::dispatch(KeyPressedEvent& event) {
		for(auto &listener : listeners) {
			if(event.handled) break;
			event.handled = listener->onKeyPressedEvent(event);
		}
		event.handled = KeyEventListener::dispatch(event);
		return event.handled;
	}

	std::vector<KeyPressedEventListener*> KeyPressedEventListener::listeners;

	KeyReleasedEvent::KeyReleasedEvent(int keyCode) : KeyEvent(keyCode) {}

	std::string KeyReleasedEvent::toString() const {
		std::stringstream ss;
		ss << "KeyReleasedEvent: " << keyCode;
		return ss.str();
	};

	KeyReleasedEventListener::KeyReleasedEventListener() {
		listeners.push_back(this);
	}

	KeyReleasedEventListener::~KeyReleasedEventListener() {
		listeners.erase(
			std::remove(
				listeners.begin(),
				listeners.end(),
				this
			),
			listeners.end()
		);
	}

	bool KeyReleasedEventListener::dispatch(KeyReleasedEvent& event) {
		for(auto &listener : listeners) {
			if(event.handled) break;
			event.handled = listener->onKeyReleasedEvent(event);
		}
		event.handled = KeyEventListener::dispatch(event);
		return event.handled;
	}

	std::vector<KeyReleasedEventListener*> KeyReleasedEventListener::listeners;
}


