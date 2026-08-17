#pragma once
#include <string>
namespace deiig::debugger { int run(const std::string&exe); int attach(int pid); int command(const std::string&cmd); }
