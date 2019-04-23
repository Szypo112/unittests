#pragma once
#include "../UnitTests/ConnectionExtractor.h"

namespace UnitTests
{
	struct ConnectionExtractorTestParams
	{
		std::string m_connection_string;
		Display::Connection m_expected_connection;
	};

	class ConnectionExtractorShould
	{
	public:
		Display::ConnectionExtractor m_sut;
	};
}