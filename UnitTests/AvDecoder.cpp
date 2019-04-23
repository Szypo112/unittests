#include "pch.h"
#include "AvDecoder.h"
namespace Display
{
	AvDecoder::AvDecoder(std::shared_ptr<IDisplayProvider> a_display_provider, std::shared_ptr<ICommandSkipper> a_command_skipper)
		: m_display_provider(a_display_provider)
		, m_command_skipper(a_command_skipper)
	{
	}

	bool AvDecoder::ConnectDisplay(const std::string & a_connection, int a_display_id)
	{
		if (!m_display_provider->IsDisplayInRange(a_display_id))
		{
			return false;
		}

		if (!m_command_skipper->ShouldSkipCommand(a_display_id, "ConnectDisplay"))
		{
			return false;
		}

		auto display = m_display_provider->GetDisplay(a_display_id);

		return display->Connect(a_connection, a_display_id);
	}

	bool AvDecoder::DisconnectDisplay(int a_display_id)
	{
		if (!m_display_provider->IsDisplayInRange(a_display_id))
		{
			return false;
		}

		if (!m_command_skipper->ShouldSkipCommand(a_display_id, "DisconnectDisplay"))
		{
			return false;
		}

		auto display = m_display_provider->GetDisplay(a_display_id);

		return display->Disconnect(a_display_id);
	}

	bool AvDecoder::HasAudio(int a_display_id)
	{
		if (!m_display_provider->IsDisplayInRange(a_display_id))
		{
			return false;
		}

		if (!m_command_skipper->ShouldSkipCommand(a_display_id, "HasAudio"))
		{
			return false;
		}

		auto display = m_display_provider->GetDisplay(a_display_id);

		return display->HasAudio(a_display_id);
	}

	bool AvDecoder::HasVideo(int a_display_id)
	{
		if (!m_display_provider->IsDisplayInRange(a_display_id))
		{
			return false;
		}

		if (!m_command_skipper->ShouldSkipCommand(a_display_id, "HasVideo"))
		{
			return false;
		}

		auto display = m_display_provider->GetDisplay(a_display_id);

		return display->HasVideo(a_display_id);
	}
}
