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
		std::unique_ptr<Display::AvDecoder> m_sut;
		fakeit::Mock<Display::IDisplayProvider> m_display_provider_mock;
	};

	AvDecoderShould::AvDecoderShould()
	{
		fakeit::Fake(Dtor(m_display_provider_mock));
		m_sut = std::make_unique<Display::AvDecoder>(std::shared_ptr<Display::IDisplayProvider>(&m_display_provider_mock.get()), nullptr);
	}
}