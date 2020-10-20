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

			inline LayerStack& getStack() { return stack; }
		private:
			std::unique_ptr<Window> window;
			bool running = true;
			LayerStack stack;
			Layer* layer;
	};

	Application* createApplication();

}
