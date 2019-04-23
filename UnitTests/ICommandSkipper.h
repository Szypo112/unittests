#pragma once
namespace Display
{
	class ICommandSkipper
	{
	public:
		virtual ~ICommandSkipper() = default;
	public:
		virtual bool ShouldSkipCommand(int a_display_id, const std::string & a_command) = 0;
	};
}