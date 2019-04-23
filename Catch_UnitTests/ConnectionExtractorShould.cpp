#include "ConnectionExtractorShould.h"
#include <catch.hpp>

namespace UnitTests
{
	TEST_CASE_METHOD(ConnectionExtractorShould, "CoretlyExtractConnectionString")
	{
		auto data = GENERATE(values<ConnectionExtractorTestParams>(
			{
				{ "1,camera_name,camera_ip,camera_port", {1, "camera_name", "camera_ip", "camera_port"}},
				{ "2,camera_name,camera_ip,camera_port", {1, "camera_name", "camera_ip", "camera_port"}}
			}));

		REQUIRE_THAT(m_sut.Extract(data.m_connection_string),
			Catch::Matchers::Predicate<Display::Connection>([data](const Display::Connection & a_connection)
		{
			return data.m_expected_connection.a_display_id == a_connection.a_display_id &&
				data.m_expected_connection.a_camera_name == a_connection.a_camera_name &&
				data.m_expected_connection.a_camera_port == a_connection.a_camera_port;
		}));
	}
}