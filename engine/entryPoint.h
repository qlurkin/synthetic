#pragma once

#ifdef SYN_PLATFORM_WINDOWS

extern syn::Application* syn::createApplication();

int main(int argc, char** argv) {
	auto app = syn::createApplication();
	app->run();
	delete app;

	return 0;
}

#endif