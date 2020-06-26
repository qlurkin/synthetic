#pragma once

#ifdef SYN_PLATFORM_WINDOWS

extern syn::Application* syn::createApplication();

int main(int argc, char** argv) {
	syn::Log::init();
	SYN_CORE_INFO("Starting Synthetic Engine");
	auto app = syn::createApplication();

	syn::Event* event = new syn::Event();
	syn::Dispatcher::dispatch(*event);

	app->run();
	delete app;

	return 0;
}

#endif
