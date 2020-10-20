#include <Synthetic/synthetic.h>

class Sandbox : public syn::Application, public syn::Listener<syn::Event>, public syn::Listener<syn::KeyPressedEvent> {
	public:
	Sandbox() {
		SYN_WARN("Sandbox starting");
		syn::Layer* myLayer = new syn::Layer("myLayer");
		getStack().pushLayer(myLayer);
		myLayer->add<syn::Event>(this);
		myLayer->add<syn::KeyPressedEvent>(this);
	}

	~Sandbox() {

	}

	bool on(syn::Event& event) {
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
