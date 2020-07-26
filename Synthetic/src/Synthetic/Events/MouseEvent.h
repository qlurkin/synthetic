#pragma once

#include "Event.h"

namespace syn {

	class MouseEvent : public Event {
		public:
			virtual bool dispatch() override {
				bool res = Dispatcher::dispatch(*this);
				if(!res) {
					res = Event::dispatch();
				}
				return res;
			}

		protected:
			MouseEvent() {}
	};

	class MouseMovedEvent : public MouseEvent {
		public:
			MouseMovedEvent(float x, float y): mouseX(x), mouseY(y) {}

			float getX() const { return mouseX; }
			float getY() const { return mouseY; }

			std::string toString() const override {
				std::stringstream ss;
				ss << "MouseMovedEvent: " << mouseX << ", " << mouseY;
				return ss.str();
			}

			virtual bool dispatch() override {
				bool res = Dispatcher::dispatch(*this);
				if(!res) {
					res = MouseEvent::dispatch();
				}
				return res;
			}

		private:
			float mouseX, mouseY;
	};

	class MouseScrolledEvent : public MouseEvent {
		public:
			MouseScrolledEvent(float xOffset, float yOffset): xOffset(xOffset), yOffset(yOffset) {}

			float getXOffset() const { return xOffset; }
			float getYOffset() const { return yOffset; }

			std::string toString() const override {
				std::stringstream ss;
				ss << "MouseScrolledEvent: " << getXOffset() << ", " << getYOffset();
				return ss.str();
			}

			virtual bool dispatch() override {
				bool res = Dispatcher::dispatch(*this);
				if(!res) {
					res = MouseEvent::dispatch();
				}
				return res;
			}

		private:
			float xOffset, yOffset;
	};

	class MouseButtonEvent : public MouseEvent {
		public:
			inline int getMouseButton() const { return button; }

			virtual bool dispatch() override {
				bool res = Dispatcher::dispatch(*this);
				if(!res) {
					res = MouseEvent::dispatch();
				}
				return res;
			}
		
		protected:
			MouseButtonEvent(int button)
				: button(button) {}

		private:
			int button;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent {
		public:
			MouseButtonPressedEvent(int button)
				: MouseButtonEvent(button) {}

			std::string toString() const override {
				std::stringstream ss;
				ss << "MouseButtonPressedEvent: " << getMouseButton();
				return ss.str();
			}

			virtual bool dispatch() override {
				bool res = Dispatcher::dispatch(*this);
				if(!res) {
					res = MouseButtonEvent::dispatch();
				}
				return res;
			}
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent {
		public:
			MouseButtonReleasedEvent(int button)
				: MouseButtonEvent(button) {}

			std::string toString() const override {
				std::stringstream ss;
				ss << "MouseButtonReleasedEvent: " << getMouseButton();
				return ss.str();
			}

			virtual bool dispatch() override {
					bool res = Dispatcher::dispatch(*this);
					if(!res) {
						res = MouseButtonEvent::dispatch();
					}
					return res;
			}
	};

}