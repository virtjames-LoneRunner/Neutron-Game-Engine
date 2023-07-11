#pragma once

#ifdef NT_PLATFORM_WINDOWS

extern Neutron::Application* Neutron::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Neutron::CreateApplication();
	app->Run();
	delete app;
}

#endif
