#include "findconfdir.hpp"
#include "projectname.hpp"
#include <cstdlib>
#include <filesystem>
extern "C" {
#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>
}

namespace fs = std::filesystem;
std::string findconfdir(bool create) {
    fs::path respath;
    const char *config_path = std::getenv("XDG_CONFIG_HOME");
    if (config_path != nullptr)
        respath = config_path;
    else {
        respath = getpwuid(getuid())->pw_dir;
        respath /= ".config";
    }
    respath /= PROJECTNAME;
    if (create) {
        if (!fs::exists(respath))
            fs::create_directory(respath);
        else if (!fs::is_directory(respath))
            throw 1;
        return respath.string();
    } else if (!fs::exists(respath) || !fs::is_directory(respath))
        throw 1;
    return respath.string();
}