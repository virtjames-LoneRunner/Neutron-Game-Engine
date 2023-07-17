#pragma once

#include "Core.h"
#include "Window.h"

#include "Neutron/LayerStack.h"
#include "Neutron/Events/Event.h"
#include "Neutron/Events/ApplicationEvent.h"


namespace Neutron {
	class NEUTRON_API Application {
	public:
		Application();
		~Application();

		void Run();
		void OnEvent(Event& event);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}

