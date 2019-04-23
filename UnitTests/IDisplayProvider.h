#pragma once
#include <memory>
#include <iostream>
#include "IDisplay.h"

namespace Display
{
	class IDisplayProvider
	{
	public:
		virtual ~IDisplayProvider() = default;
	public:
		virtual std::shared_ptr<IDisplay> GetDisplay(int a_display_id) = 0;
		virtual bool IsDisplayInRange(int a_display_id) = 0;
	};
}