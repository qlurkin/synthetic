#pragma once

#include "Event.h"

namespace syn {

	class MouseMovedEvent : public Event {
		public:
			MouseMovedEvent(float x, float y): mouseX(x), mouseY(y) {}

			float getX() const { return mouseX; }
			float getY() const { return mouseY; }

			std::string toString() const override {
				std::stringstream ss;
				ss << "MouseMovedEvent: " << mouseX << ", " << mouseY;
				return ss.str();
			}

		private:
			float mouseX, mouseY;
	};

	class MouseScrolledEvent : public Event {
		public:
			MouseScrolledEvent(float xOffset, float yOffset): xOffset(xOffset), yOffset(yOffset) {}

			float getXOffset() const { return xOffset; }
			float getYOffset() const { return yOffset; }

			std::string toString() const override {
				std::stringstream ss;
				ss << "MouseScrolledEvent: " << getXOffset() << ", " << getYOffset();
				return ss.str();
			}

		private:
			float xOffset, yOffset;
	};

	class MouseButtonEvent : public Event {
		public:
			inline int getMouseButton() const { return button; }
		
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
	};

}