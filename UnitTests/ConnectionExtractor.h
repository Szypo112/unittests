#pragma once
#include "Connection.h"

namespace Display
{
	class ConnectionExtractor
	{
	public:
		Connection Extract(const std::string & a_connection);
	private:
		const char DELIMITER = ',';
		const int DISPLAY_ID_POS = 0;
		const int CAMERA_NAME_POS = 1;
		const int CAMERA_IP_POS = 2;
		const int CAMERA_PORT_POS = 3;
	};
}