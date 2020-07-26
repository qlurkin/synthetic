#include "pch.h"
#include "GLFWWindow.h"

#include "Synthetic/Events/Event.h"

namespace syn {

	static bool GLFWInitialized = false;

	Window* Window::create(const WindowProps& props)
	{
		return new GLFWWindow(props);
	}

	GLFWWindow::GLFWWindow(const WindowProps& props)
	{
		data.title = props.title;
		data.width = props.width;
		data.height = props.height;

		SYN_CORE_INFO("Creating window {0} ({1}, {2})", props.title, props.width, props.height);

		if (!GLFWInitialized)
		{
			// TODO: glfwTerminate on system shutdown
			int success = glfwInit();
			SYN_CORE_ASSERT(success, "Could not intialize GLFW!");

			GLFWInitialized = true;
		}

		window = glfwCreateWindow((int)props.width, (int)props.height, data.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(window);
		glfwSetWindowUserPointer(window, &data);
		setVSync(true);

		// Set GLFW Callbacks
		glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height) {
			WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);
			data.width = width;
			data.height = height;

			WindowResizeEvent event = WindowResizeEvent(width, height);
			event.dispatch();
		});

		glfwSetWindowCloseCallback(window, [](GLFWwindow* window) {
			WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			event.dispatch();
		});

		glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods)  {
			WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);

			switch(action) {
				case GLFW_PRESS: {
					KeyPressedEvent event(key, 0);
					event.dispatch();
					break;
				}
				case GLFW_RELEASE: {
					KeyReleasedEvent event(key);
					event.dispatch();
					break;
				}
				case GLFW_REPEAT: {
					KeyPressedEvent event(key, 1);
					event.dispatch();
					break;
				}
			}
		});

		glfwSetCharCallback(window, [](GLFWwindow* window, unsigned int keycode) {
			WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);

			KeyTypedEvent event(keycode);
			event.dispatch();
		});

		glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods) {
			WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);

			switch (action) {
				case GLFW_PRESS: {
					MouseButtonPressedEvent event(button);
					event.dispatch();
					break;
				}
				case GLFW_RELEASE: {
					MouseButtonReleasedEvent event(button);
					event.dispatch();
					break;
				}
			}
		});

		glfwSetScrollCallback(window, [](GLFWwindow* window, double xOffset, double yOffset) {
			WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);

			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			event.dispatch();
		});

		glfwSetCursorPosCallback(window, [](GLFWwindow* window, double xPos, double yPos) {
			WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);

			MouseMovedEvent event((float)xPos, (float)yPos);
			event.dispatch();
		});

	}

	GLFWWindow::~GLFWWindow()
	{
		glfwDestroyWindow(window);
	}

	void GLFWWindow::onUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	void GLFWWindow::setVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		data.vsync = enabled;
	}

	bool GLFWWindow::isVSync() const
	{
		return data.vsync;
	}

}
