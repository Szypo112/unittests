#include "pch.h"
#include "AvDecoderShould.h"

namespace UnitTests
{
	TEST_F(AvDecoderShould, ReturnFalseWhenDisplayIsNotInRangeOnCallConnectDisplay)
	{
		fakeit::Fake(Dtor(m_display_provider_mock));
		fakeit::When(Method(m_display_provider_mock, IsDisplayInRange)).Return(false);

		ASSERT_FALSE(m_sut->ConnectDisplay({}, 0));
	}
}