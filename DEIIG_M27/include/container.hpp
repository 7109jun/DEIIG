#pragma once
#include <filesystem>
#include <string>
#include <vector>

namespace deiig::container {

enum class Runtime { None, Docker, Podman };

struct Status {
    Runtime runtime = Runtime::None;
    bool available = false;
    std::string version;
};

Status detect();
std::string runtime_name(Runtime r);
std::string config_file(const std::filesystem::path& project_dir);

int init_project(const std::filesystem::path& project_dir,
                 const std::string& image,
                 const std::string& workdir = "/workspace");

int build(const std::filesystem::path& project_dir,
          const std::string& tag,
          const std::string& context = ".",
          const std::string& dockerfile = "Containerfile");

int run(const std::filesystem::path& project_dir,
        const std::string& image,
        const std::vector<std::string>& args = {},
        const std::string& name = "");

int exec(const std::filesystem::path& project_dir,
         const std::string& container,
         const std::vector<std::string>& command);

int stop(const std::filesystem::path& project_dir, const std::string& container);
int remove(const std::filesystem::path& project_dir, const std::string& container);
int logs(const std::filesystem::path& project_dir, const std::string& container, bool follow = false);
int images(const std::filesystem::path& project_dir);
int ps(const std::filesystem::path& project_dir, bool all = false);
int pull(const std::filesystem::path& project_dir, const std::string& image);

std::string quote(const std::string& value);
std::string command_prefix(const Status& status);

} // namespace deiig::container
