#pragma once

#include "Core.h"
#include "Window.h"
#include "Events/ApplicationEvent.h"


namespace Neutron {
	class NEUTRON_API Application {
	public:
		Application();
		~Application();

		void Run();
		void OnEvent(Event& event);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}

