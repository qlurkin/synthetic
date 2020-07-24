#pragma once

#include "core.h"
#include "Window.h"
#include "Events/Event.h"

namespace syn {

	class Application: public Listener<WindowCloseEvent>{
		public:
			Application();
			virtual ~Application();

			bool on(WindowCloseEvent& event) override;

			void run();
		private:
			std::unique_ptr<Window> window;
			bool running = true;
	};

	Application* createApplication();

}
