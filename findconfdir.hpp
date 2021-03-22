#include <string>

std::string findconfdir(bool create = true);
// Returns string with config directory
// throws 1 if something besides a directory
// throws 1 if create = false and path doesnt exist
// creates dir if create = true
// also checks XDG_CONFIG_HOME env variable