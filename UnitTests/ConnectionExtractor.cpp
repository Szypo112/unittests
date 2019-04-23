#include "pch.h"
#include "ConnectionExtractor.h"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

namespace Display
{
	Connection ConnectionExtractor::Extract(const std::string & a_connection)
	{
		std::vector<std::string> tokens;
		std::string token;



		std::stringstream token_stream(a_connection);

		while (std::getline(token_stream, token, ','))
		{
			tokens.push_back(token);
		}

		if (tokens.size() < 4)
		{
			return { -1, "","","", };
		}

		return { std::atoi(tokens[DISPLAY_ID_POS].c_str()),  tokens[CAMERA_NAME_POS],  tokens[CAMERA_IP_POS],  tokens[CAMERA_PORT_POS] };
	}
}