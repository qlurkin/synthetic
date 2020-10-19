#include "pch.h"
#include "Listener.h"

namespace syn {
	std::unordered_map <std::type_index, std::vector<Listener<>*>> Listener<>::allListeners;
}
