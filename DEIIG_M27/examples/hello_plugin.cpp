#include "../include/plugin_api.hpp"
#include <cstdio>
#include <cstring>
#include <string>

static int hello_command(int argc, const char* const* argv, void*) {
    std::printf("Hello from DEIIG plugin");
    if (argc > 1) {
        std::printf(":");
        for (int i = 1; i < argc; ++i) std::printf(" %s", argv[i]);
    }
    std::printf("\n");
    return 0;
}

DEIIG_PLUGIN_EXPORT const char* deiig_plugin_init(const DeiigPluginApi* api) {
    if (!api || api->api_version != DEIIG_PLUGIN_API_VERSION) return nullptr;
    api->register_command(api->host, "hello-plugin", "Print a greeting from the sample plugin", hello_command, nullptr);
    api->log(api->host, "hello_plugin loaded");
    return "hello_plugin";
}

DEIIG_PLUGIN_EXPORT void deiig_plugin_shutdown(const DeiigPluginApi* api) {
    if (api && api->log) api->log(api->host, "hello_plugin unloaded");
}
