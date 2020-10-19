#pragma once

#include "Event.h"

namespace syn {
	class KeyEvent : public Event {
		public:
			inline int getKeyCode() const {
				return keyCode;
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
	};

	class KeyTypedEvent : public KeyEvent {
		public:
			KeyTypedEvent(int keycode): KeyEvent(keycode) {}

			std::string toString() const override {
				std::stringstream ss;
				ss << "KeyTypedEvent: " << getKeyCode();
				return ss.str();
			}
	};
}