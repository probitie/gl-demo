#pragma once

#include <string>
#include <iostream>

// to make shorter names in debug log, (for Windows - \\, for linux/mac - /)
#define RD_FILENAME_ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

// TODO reduce duplicated code


// you can use it like this "debuglog("Hello " << user->name)"
#define debuglog(message) std::cout << "[DEBUG] " << RD_FILENAME_ << "::" << __LINE__ \
<< "::" << __FUNCTION__ << ":: " << message << "\n"

#define infolog(message) std::cout << "[INFO] " << RD_FILENAME_ << "::" << __LINE__ \
<< "::" << __FUNCTION__ << ":: " << message << "\n"

#define errorlog(message) std::cerr << "[ERROR] " << RD_FILENAME_ << "::" << __LINE__ \
<< "::" << __FUNCTION__ << ":: " << message << "\n"
