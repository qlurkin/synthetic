#pragma once

#include "Synthetic/core.h"
#include "Layer.h"

namespace syn {

	class LayerStack {
		public:
			LayerStack();
			~LayerStack();

			void pushLayer(Layer* layer);
			void pushOverlay(Layer* overlay);
			void popLayer(Layer* layer);
			void popOverlay(Layer* overlay);

			template<class T>
			bool dispatch(T& event) {
				bool res = false;
				for(Layer* layer: layers) {
					res = layer->dispatch(event);
					if(res) break;
				}

				return res;
			}

			std::vector<Layer*>::iterator begin() { return layers.begin(); }
			std::vector<Layer*>::iterator end() { return layers.end(); }
		private:
			std::vector<Layer*> layers;
			std::vector<Layer*>::iterator layerInsert;
	};

}