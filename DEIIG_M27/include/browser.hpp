#pragma once
#include <string>
namespace deiig::browser {
int open(const std::string& url);
int search(const std::string& engine, const std::string& query);
}
