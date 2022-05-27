#pragma once
#include "UIUtils.hpp"
#include <limits>

#define AUTOSIZE INT_MIN

struct UIFormat
{
	enum class BorderStyle
	{
		none,
		solid,
		dotted,
		dashed,
		ddouble
	};
	enum class VerticalAlign
	{
		center,
		top,
		buttom
	};
	enum class HorizontalAlign
	{
		center,
		left,
		right
	};
	enum class Positioning
	{
		absolute,
		vertical,
		horizontal
	};

	UIFormat(
		iv2 topLeftPoint,
		iv2 size = FILLV2(AUTOSIZE),
		uv4 margin = ZEROV4, 
		uv4 border = ZEROV4, 
		vec4<BorderStyle> borderStyle = FILLV4(BorderStyle::none),
		uv4 padding = ZEROV4, 
		VerticalAlign vAlign = VerticalAlign::center, 
		HorizontalAlign hAlign = HorizontalAlign::center,
		Positioning position = Positioning::absolute);

	void CalcContent();
	void move(iv2 delta);
	void moveTo(iv2 point);

	iv4 block, content = ZEROV4; // size - outer perimeter; content - content perimeter
	uv4 margin, border, padding;
	vec4<BorderStyle> borderStyle;
	VerticalAlign vAlign;
	HorizontalAlign hAlign;
	Positioning position = Positioning::absolute;
	iv2 topLeftPoint, size;
};