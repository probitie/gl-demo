#pragma once

#include <string>
#include <iostream>

// to make shorter names in debug log, (for Windows - \\, for linux/mac - /)
#define RD_FILENAME_ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

#define RD_GET_PLACE_IN_CODE(line_offset) (std::ostringstream{} << RD_FILENAME_ << "::" << __LINE__ \
<< "::" << __FUNCTION__ << ":: ").str()


// you can use it like this "debuglog("Hello " << user->name)"
#define RD_WRITE_LOG(outbuffer, level, message) outbuffer << "[" << (level) \
<< "] \t" << RD_GET_PLACE_IN_CODE(0) << message << "\n"

#define debuglog(message) RD_WRITE_LOG(std::cout, "DEBUG", message)
#define infolog(message) RD_WRITE_LOG(std::cout, "INFO", message)
#define errorlog(message) RD_WRITE_LOG(std::cerr, "ERROR", message)
