#pragma once

#include "Event.h"

namespace syn {
	class KeyEvent : public Event {
		public:
			inline int getKeyCode() const {
				return keyCode;
			}

			virtual bool dispatch() override {
				bool res = Listener<KeyEvent>::dispatch(*this);
				if(!res) {
					res = Event::dispatch();
				}
				return res;
			}
		
		protected:
			KeyEvent(int keyCode): keyCode(keyCode) {}
		
		private:
			int keyCode;
	};

	class KeyPressedEvent : public KeyEvent {
		public:
			KeyPressedEvent(int keyCode, int repeatCount): KeyEvent(keyCode), repeatCount(repeatCount) {}

			inline int getRepeatCount() const {
				return repeatCount;
			}

			virtual std::string toString() const override {
				std::stringstream ss;
				ss << "KeyPressedEvent: " << getKeyCode() << " (repeat=" << getRepeatCount() << ")";
				return ss.str();
			}

			virtual bool dispatch() override {
				bool res = Listener<KeyPressedEvent>::dispatch(*this);
				if(!res) {
					res = KeyEvent::dispatch();
				}
				return res;
			}
		
		private:
			int repeatCount;
	};

	class KeyReleasedEvent : public KeyEvent {
		public:
			KeyReleasedEvent(int keyCode): KeyEvent(keyCode) {}

			virtual std::string toString() const override {
				std::stringstream ss;
				ss << "KeyReleasedEvent (key=" << getKeyCode() << ")";
				return ss.str();
			}

			virtual bool dispatch() override {
				bool res = Listener<KeyReleasedEvent>::dispatch(*this);
				if(!res) {
					res = KeyEvent::dispatch();
				}
				return res;
			}
	};

	class KeyTypedEvent : public KeyEvent {
		public:
			KeyTypedEvent(int keycode): KeyEvent(keycode) {}

			std::string toString() const override {
				std::stringstream ss;
				ss << "KeyTypedEvent: " << getKeyCode();
				return ss.str();
			}

			virtual bool dispatch() override {
				bool res = Listener<KeyTypedEvent>::dispatch(*this);
				if(!res) {
					res = KeyEvent::dispatch();
				}
				return res;
			}
	};
}