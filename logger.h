#pragma once

#include <string>

// to make shorter names in debug log, (for Windows - \\, for linux/mac - /)
#define FILENAME_ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

// TODO reduce duplicated code

// dont forget to include <iostream>
// you can use it like this "debuglog("Hello " << user->name)"
#define debuglog(message) std::cout << "[DEBUG] " << FILENAME_ << "::" << __LINE__ \
<< "::" << __FUNCTION__ << ":: " << message << "\n"

#define infolog(message) std::cout << "[INFO] " << FILENAME_ << "::" << __LINE__ \
<< "::" << __FUNCTION__ << ":: " << message << "\n"

#define errorlog(message) std::cerr << "[ERROR] " << FILENAME_ << "::" << __LINE__ \
<< "::" << __FUNCTION__ << ":: " << message << "\n"
