#pragma once

#include "core.h"

namespace syn {

	class SYN_API Application {
		public:
		Application();
		virtual ~Application();

		void run();
	};

	Application* createApplication();

}
