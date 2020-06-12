#include <synthetic.h>

class Sandbox : public syn::Application {
	public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

syn::Application* syn::createApplication() {
	return new Sandbox();
}
