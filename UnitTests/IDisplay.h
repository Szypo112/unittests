#pragma once
#include <string>

namespace Display
{
	class IDisplay
	{
	public:
		virtual ~IDisplay() = default;
	public:
		virtual bool Connect(const std::string & a_connection, int a_display_id) = 0;
		virtual bool Disconnect(int a_display_id) = 0;

		virtual bool HasVideo(int a_display_id) = 0;
		virtual bool HasAudio(int a_display_id) = 0;
		
		virtual int GetAudioVolume(int a_display_id) = 0;
	};
}