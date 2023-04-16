#pragma once

#include <string>
#include <iostream>

// to make shorter names in debug log, (for Windows - \\, for linux/mac - /)
#define RD_FILENAME_ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

/**
 * \brief makes a string from ("text " << var1 << ";")
 * be aware that it makes an output slower
 * \param stream_msg something like "text " << var1 << ";"
 */
#define RD_STREAM_TO_STR(stream_msg) (std::ostringstream{} << stream_msg).str()

#define RD_GET_PLACE_IN_CODE(line_offset) RD_STREAM_TO_STR(RD_FILENAME_ << "::" << __LINE__ \
<< "::" << __FUNCTION__ << ":: ")

/**
 * \brief turns glm::vec3 to a string
 * \param vec3 
 */
#define RD_VEC3_TO_STR(vec3) RD_STREAM_TO_STR(\
"{"<< (vec3).x << "; "\
<< (vec3).y << "; "\
<< (vec3).z << "} "\
)

// you can use it like this "debuglog("Hello " << user->name)"
#define RD_WRITE_LOG(outbuffer, level, message) outbuffer << "[" << (level) \
<< "]\t" << RD_GET_PLACE_IN_CODE(0) << message << "\n"

// TODO add logger levels
#define debuglog(message) RD_WRITE_LOG(std::cout, "DEBUG", message) // disconnected debug output for now
#define infolog(message) RD_WRITE_LOG(std::cout, "INFO", message)
#define errorlog(message) RD_WRITE_LOG(std::cerr, "ERROR", message)
