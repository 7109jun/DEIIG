#pragma once
#include <filesystem>
#include <string>
#include <vector>

namespace deiig {

struct AppStatePaths {
    std::filesystem::path root;
    std::filesystem::path config;
    std::filesystem::path log;
    std::filesystem::path crash_marker;
};

AppStatePaths app_state_paths();
void app_log(const std::string& message);
void mark_startup(bool safe_mode);
void mark_clean_exit();
bool previous_run_was_unclean();

// Lightweight installation/environment diagnostics used by DEIIG's 1.0 shell.
struct DiagnosticResult {
    std::string name;
    bool ok = false;
    std::string detail;
};
std::vector<DiagnosticResult> run_diagnostics(const std::filesystem::path& project_dir);

} // namespace deiig
