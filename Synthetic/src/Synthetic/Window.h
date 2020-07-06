#pragma once

#include "pch.h"

#include "Synthetic/core.h"
#include "Events/Event.h"

namespace syn {

	struct WindowProps
	{
		std::string title;
		unsigned int width;
		unsigned int height;

		WindowProps(const std::string& title = "Synthetic Engine",
			        unsigned int width = 1280,
			        unsigned int height = 720)
			: title(title), width(width), height(height)
		{
		}
	};

	// Interface representing a desktop system based Window
	class SYN_API Window
	{
	public:
		virtual ~Window() {}

		virtual void onUpdate() = 0;

		virtual unsigned int getWidth() const = 0;
		virtual unsigned int getHeight() const = 0;

		// Window attributes
		virtual void setEventCallback(const EventCallbackFn& callback) = 0;
		virtual void setVSync(bool enabled) = 0;
		virtual bool isVSync() const = 0;

		static Window* create(const WindowProps& props = WindowProps());

	private:
		GLFWwindow* window;

		struct WindowData {
			std::string title;
			unsigned int width, height;
			bool vsync;

			EventCallbackFn eventCallback;
		};

		WindowData data;
	};

}
