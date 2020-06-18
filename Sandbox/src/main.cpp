#include <Synthetic/synthetic.h>

class Sandbox : public syn::Application, public syn::EventListener, public syn::KeyEventListener {
	public:
	Sandbox() {
		SYN_WARN("Sandbox starting");
	}

	~Sandbox() {

	}

	bool onEvent(syn::Event& event) {
		SYN_TRACE("Event happens");
		return false;
	}

	bool onKeyEvent(syn::KeyEvent& event) {
		SYN_TRACE("KeyEvent happens");
		return false;
	}
};

syn::Application* syn::createApplication() {
	return new Sandbox();
}
