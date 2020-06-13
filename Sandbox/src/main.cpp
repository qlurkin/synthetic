#include <synthetic.h>

class Sandbox : public syn::Application {
	public:
	Sandbox() {
		SYN_WARN("Sandbox starting");
	}

	~Sandbox() {

	}
};

syn::Application* syn::createApplication() {
	return new Sandbox();
}
