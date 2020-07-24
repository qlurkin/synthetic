#include <Synthetic/synthetic.h>

class Sandbox : public syn::Application, public syn::Listener<syn::WindowResizeEvent>, public syn::Listener<syn::KeyPressedEvent> {
	public:
	Sandbox() {
		SYN_WARN("Sandbox starting");
	}

	~Sandbox() {

	}

	bool on(syn::WindowResizeEvent& event) {
		SYN_TRACE(event.toString());
		return false;
	}

	bool on(syn::KeyPressedEvent& event) {
		SYN_TRACE(event.toString());
		return false;
	}
};

syn::Application* syn::createApplication() {
	return new Sandbox();
}
