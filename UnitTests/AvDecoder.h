#pragma once
#include <memory>
#include <iostream>
#include "IDisplayProvider.h"
#include "ICommandSkipper.h"

namespace Display
{
	class AvDecoder
	{
	public:
		AvDecoder(std::shared_ptr<IDisplayProvider> a_display_provider, std::shared_ptr<ICommandSkipper> a_command_skipper);
	public:
		bool ConnectDisplay(const std::string & a_connection, int a_display_id);
		bool DisconnectDisplay(int a_display_id);
		bool HasAudio(int a_display_id);
		bool HasVideo(int a_display_id);
	private:
		std::shared_ptr<IDisplayProvider> m_display_provider;
		std::shared_ptr<ICommandSkipper> m_command_skipper;
	};
}