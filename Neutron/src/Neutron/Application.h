#pragma once

#include "Core.h"

namespace Neutron {
	class NEUTRON_API Application {
	public:
		Application();
		~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}

