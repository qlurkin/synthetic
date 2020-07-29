#pragma once

#include "Event.h"

namespace syn {

	class ApplicationEvent: public Event {
		public:
			virtual bool dispatch() override {
				bool res = Listener<ApplicationEvent>::dispatch(*this);
				if(!res) {
					res = Event::dispatch();
				}
				return res;
			}
		
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

			virtual bool dispatch() override {
				bool res = Listener<WindowResizeEvent>::dispatch(*this);
				if(!res) {
					res = ApplicationEvent::dispatch();
				}
				return res;
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

			virtual bool dispatch() override {
				bool res = Listener<WindowCloseEvent>::dispatch(*this);
				if(!res) {
					res = ApplicationEvent::dispatch();
				}
				return res;
			}
	};

	class AppTickEvent : public ApplicationEvent {
		public:
			AppTickEvent() = default;

			std::string toString() const override {
				return "AppTickEvent";
			}

			virtual bool dispatch() override {
				bool res = Listener<AppTickEvent>::dispatch(*this);
				if(!res) {
					res = ApplicationEvent::dispatch();
				}
				return res;
			}
	};

	class AppUpdateEvent : public ApplicationEvent {
		public:
			AppUpdateEvent() = default;

			std::string toString() const override {
				return "AppUpdateEvent";
			}

			virtual bool dispatch() override {
				bool res = Listener<AppUpdateEvent>::dispatch(*this);
				if(!res) {
					res = ApplicationEvent::dispatch();
				}
				return res;
			}
	};

	class AppRenderEvent : public ApplicationEvent {
		public:
			AppRenderEvent() = default;

			std::string toString() const override {
				return "AppRenderEvent";
			}

			virtual bool dispatch() override {
				bool res = Listener<AppRenderEvent>::dispatch(*this);
				if(!res) {
					res = ApplicationEvent::dispatch();
				}
				return res;
			}
	};
}