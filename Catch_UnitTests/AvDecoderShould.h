#pragma once
#include <catch.hpp>
#include <fakeit.hpp>
#include "../UnitTests/IDisplayProvider.h"
#include "../UnitTests/ICommandSkipper.h"
#include "../UnitTests/AvDecoder.h"

namespace UnitTests
{
	class AvDecoderShould
	{
	protected:
		fakeit::Mock<Display::IDisplayProvider> m_display_provider_mock;
		fakeit::Mock<Display::ICommandSkipper> m_command_skipper;

		std::unique_ptr<Display::AvDecoder> m_sut;
	public:
		AvDecoderShould()
		{
			fakeit::Fake(Dtor(m_display_provider_mock));
			fakeit::Fake(Dtor(m_command_skipper));
			m_sut =
				std::make_unique<Display::AvDecoder>(std::shared_ptr<Display::IDisplayProvider>(&m_display_provider_mock.get()),
					std::shared_ptr<Display::ICommandSkipper>(&m_command_skipper.get()));
		}
	};
}