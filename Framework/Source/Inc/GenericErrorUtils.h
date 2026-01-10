#pragma once

#include <cstdint>
#include <string>

class GenericErrorUtils
{
public:
	static void ReportAssertion(const char* expression, const char* file, uint32_t line, const std::string& description = "");
};