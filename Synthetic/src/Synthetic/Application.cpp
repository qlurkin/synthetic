#include "pch.h"
#include "Application.h"

namespace syn {

	Application::Application() {
		window = std::unique_ptr<Window>(Window::create(stack));
		layer = new Layer("Core Application Layer");
		stack.pushLayer(layer);
		layer->add<WindowCloseEvent>(this);
	}

	Application::~Application() {}

	bool Application::on(WindowCloseEvent& event) {
		running = false;
		return false;
	}

	void Application::run() {
		while(running) {
			window->onUpdate();
		}
	}

}
