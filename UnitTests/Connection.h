#pragma once
#include <string>

namespace Display
{
	struct Connection
	{
		int a_display_id;
		std::string  a_camera_name;
		std::string a_camera_ip;
		std::string a_camera_port;
	};
}