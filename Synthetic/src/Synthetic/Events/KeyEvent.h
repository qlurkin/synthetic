#pragma once

#include "Event.h"

namespace syn {
	class SYN_API KeyEvent : public Event {
		public:
			KeyEvent(int keyCode);
			virtual ~KeyEvent() = default;

			virtual std::string toString() const;

		protected:
			int keyCode;
	};

	class SYN_API KeyEventListener {
		public:
			KeyEventListener();
			virtual ~KeyEventListener();
			virtual bool onKeyEvent(KeyEvent& event) = 0;
			static bool dispatch(KeyEvent& event);

		private:
			static std::vector<KeyEventListener*> listeners;
	};

	class SYN_API KeyPressedEvent : public KeyEvent {
		public:
			KeyPressedEvent(int keyCode);
			virtual ~KeyPressedEvent() = default;

			virtual std::string toString() const;
	};

	class SYN_API KeyPressedEventListener {
		public:
			KeyPressedEventListener();
			virtual ~KeyPressedEventListener();
			virtual bool onKeyPressedEvent(KeyPressedEvent& event) = 0;
			static bool dispatch(KeyPressedEvent& event);

		private:
			static std::vector<KeyPressedEventListener*> listeners;
	};

	class SYN_API KeyReleasedEvent : public KeyEvent {
		public:
			KeyReleasedEvent(int keyCode);
			virtual ~KeyReleasedEvent() = default;

			virtual std::string toString() const;
	};

	class SYN_API KeyReleasedEventListener {
		public:
			KeyReleasedEventListener();
			virtual ~KeyReleasedEventListener();
			virtual bool onKeyReleasedEvent(KeyReleasedEvent& event) = 0;
			static bool dispatch(KeyReleasedEvent& event);

		private:
			static std::vector<KeyReleasedEventListener*> listeners;
	};
}
