#pragma once

#include "Event.h"

namespace syn {

	class WindowResizeEvent : public Event {
		public:
			WindowResizeEvent(unsigned int width, unsigned int height)
				: width(width), height(height) {}

			unsigned int getWidth() const { return width; }
			unsigned int getHeight() const { return height; }

			std::string toString() const override {
				std::stringstream ss;
				ss << "WindowResizeEvent: " << width << ", " << height;
				return ss.str();
			}

		private:
			unsigned int width, height;
	};

	class WindowCloseEvent : public Event {
		public:
			WindowCloseEvent() = default;
	};

	class AppTickEvent : public Event {
		public:
			AppTickEvent() = default;
	};

	class AppUpdateEvent : public Event {
		public:
			AppUpdateEvent() = default;
	};

	class AppRenderEvent : public Event {
		public:
			AppRenderEvent() = default;
	};
}