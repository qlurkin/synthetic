#pragma once

#include "Synthetic/Window.h"

#include <GLFW/glfw3.h>

namespace syn {
	class GLFWWindow : public Window {
		public:
			GLFWWindow(const WindowProps& props);
			virtual ~GLFWWindow();

			void onUpdate() override;

			inline unsigned int getWidth() const override { return data.width; }
			inline unsigned int getHeight() const override { return data.height; }

			inline void setEventCallback(const EventCallbackFn& callback) override { data.eventCallback = callback; }
			void setVSync(bool enabled) override;
			bool isVSync() const override;

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
