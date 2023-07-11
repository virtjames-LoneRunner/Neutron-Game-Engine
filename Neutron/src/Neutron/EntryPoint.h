#pragma once

#ifdef NT_PLATFORM_WINDOWS

extern Neutron::Application* Neutron::CreateApplication();

int main(int argc, char** argv)
{
	Neutron::Log::Init();
	NT_CORE_WARN("Initialized Core Logger!");
	NT_INFO("Hello!");

	auto app = Neutron::CreateApplication();
	app->Run();
	delete app;
}

#endif
