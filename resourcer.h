#pragma once
#include "libs.h"
#include "model.h"

/**
 * \brief loads resources and other objects
 */
class resourcer
{
public:
	model&& load_model(const std::string& resource_path);
};

