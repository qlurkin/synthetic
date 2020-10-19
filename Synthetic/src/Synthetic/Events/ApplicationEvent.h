#pragma once

#include "Event.h"

namespace syn {

	class ApplicationEvent: public Event {
		protected:
			ApplicationEvent() {}
	};

	class WindowResizeEvent : public ApplicationEvent {
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

	class WindowCloseEvent : public ApplicationEvent {
		public:
			WindowCloseEvent() = default;

			std::string toString() const override {
				return "WindowCloseEvent";
			}
	};

	class AppTickEvent : public ApplicationEvent {
		public:
			AppTickEvent() = default;

			std::string toString() const override {
				return "AppTickEvent";
			}
	};

	class AppUpdateEvent : public ApplicationEvent {
		public:
			AppUpdateEvent() = default;

			std::string toString() const override {
				return "AppUpdateEvent";
			}
	};

	class AppRenderEvent : public ApplicationEvent {
		public:
			AppRenderEvent() = default;

			std::string toString() const override {
				return "AppRenderEvent";
			}
	};
}