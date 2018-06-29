#pragma once

#include "Core/Utility/Types.h"
#include <Display/Layout/Layout.h>

#include <string>
#include <memory>
#include <any>

enum class WindowType { WINDOWED, FULLSCREEN, BORDERLESS, EMPTY };

struct WindowParameters {

	WindowType type;
	std::string title;
	uint pixelPosX;
	uint pixelPosY;
	uint pixelWidth;
	uint pixelHeight;
	uint monitor;

};

class SoulWindow
{

public:

	SoulWindow(WindowParameters&);
	virtual ~SoulWindow() = default;

	virtual void Draw() = 0;

	virtual void Refresh() = 0;
	virtual void Close() = 0;
	virtual void Resize(int, int) = 0;
	virtual void PositionUpdate(int, int) = 0;

	virtual void SetLayout(Layout*) = 0;

	std::any context_;
	std::unique_ptr<Layout> layout_;

	WindowParameters windowParams_;

protected:

private:

};