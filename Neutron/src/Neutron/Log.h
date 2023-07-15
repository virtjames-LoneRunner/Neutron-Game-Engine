#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"						// Allows for logging of custom types
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Neutron 
{
	class NEUTRON_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core Log Macros
#define NT_CORE_TRACE(...)   ::Neutron::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define NT_CORE_INFO(...)    ::Neutron::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NT_CORE_WARN(...)    ::Neutron::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NT_CORE_ERROR(...)   ::Neutron::Log::GetCoreLogger()->error(__VA_ARGS__)
//#define NT_CORE_FATAL(...)   ::Neutron::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log Macros
#define NT_TRACE(...)        ::Neutron::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NT_INFO(...)         ::Neutron::Log::GetClientLogger()->info(__VA_ARGS__)
#define NT_WARN(...)         ::Neutron::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NT_ERROR(...)        ::Neutron::Log::GetClientLogger()->error(__VA_ARGS__)
//#define NT_CORE_FATAL(...)   ::Neutron::Log::GetCoreLogger()->fatal(__VA_ARGS__)
