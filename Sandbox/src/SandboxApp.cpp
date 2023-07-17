#include "Neutron.h"

class ExampleLayer : public Neutron::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		NT_INFO("ExampleLayer::Update");
	}

	void OnEvent(Neutron::Event& event) override
	{
		NT_TRACE("{0}", event);
	}

};

class Sandbox : public Neutron::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Neutron::Application* Neutron::CreateApplication()
{
	return new Sandbox();
}
