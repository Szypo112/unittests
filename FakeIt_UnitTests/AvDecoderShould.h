#pragma once
#include "gtest/gtest.h"
#include <fakeit.hpp>
#include "../UnitTests/AvDecoder.h"
#include "../UnitTests/ICommandSkipper.h"
#include "../UnitTests/IDisplayProvider.h"
#include "../UnitTests/IDisplay.h"

namespace UnitTests
{
	class AvDecoderShould : public testing::Test
	{
	public:
		AvDecoderShould();
	protected:
		fakeit::Mock<Display::IDisplayProvider> m_display_provider_mock;
		fakeit::Mock<Display::ICommandSkipper> m_command_skipper;

		std::unique_ptr<Display::AvDecoder> m_sut;
	public:
		void SetUp() override
		{
			fakeit::Fake(Dtor(m_display_provider_mock));
			fakeit::Fake(Dtor(m_command_skipper));
			m_sut = 
				std::make_unique<Display::AvDecoder>(std::shared_ptr<Display::IDisplayProvider>(&m_display_provider_mock.get()), std::shared_ptr<Display::ICommandSkipper>(&m_command_skipper.get()));
		}
	};

	AvDecoderShould::AvDecoderShould()
	{

	}
}