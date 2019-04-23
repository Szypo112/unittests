#include "pch.h"
#include "AvDecoderShould.h"

using namespace fakeit;

namespace UnitTests
{
	TEST_F(AvDecoderShould, ReturnFalseWhenDisplayIsNotInRangeOnCallConnectDisplay)
	{
		fakeit::When(Method(m_display_provider_mock, IsDisplayInRange)).Return(false);

		auto result = m_sut->ConnectDisplay({}, 0);

		fakeit::Verify(Method(m_display_provider_mock, IsDisplayInRange));
		VerifyNoOtherInvocations(m_command_skipper);

		ASSERT_FALSE(result);
	}
}