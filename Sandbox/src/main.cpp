#include <Synthetic/synthetic.h>

class Sandbox : public syn::Application, public syn::Listener<syn::Event>, public syn::Listener<syn::KeyEvent> {
	public:
	Sandbox() {
		SYN_WARN("Sandbox starting");
	}

	~Sandbox() {

	}

	bool on(syn::Event& event) {
		SYN_TRACE(event.toString());
		return false;
	}

	bool on(syn::KeyEvent& event) {
		SYN_TRACE(event.toString());
		return false;
	}
};

syn::Application* syn::createApplication() {
	return new Sandbox();
}
