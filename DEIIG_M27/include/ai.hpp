#pragma once
#include <string>
namespace deiig::ai {
struct Config { std::string url, key, model; };
Config load_config();
int ask(const Config&, const std::string& prompt, std::string& response);
}
