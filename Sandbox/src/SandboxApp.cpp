#include "Neutron.h"

class Sandbox : public Neutron::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Neutron::Application* Neutron::CreateApplication()
{
	return new Sandbox();
}
