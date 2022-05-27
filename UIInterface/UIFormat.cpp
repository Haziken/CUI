#include "UIFormat.h"

UIFormat::UIFormat(
	iv2 topLeftPoint,
	iv2 size,
	uv4 margin,
	uv4 border,
	vec4<BorderStyle> borderStyle,
	uv4 padding,
	VerticalAlign vAlign,
	HorizontalAlign hAlign,
	Positioning position)
	: 
	margin(margin),
	border(border),
	borderStyle(borderStyle),
	padding(padding), vAlign(vAlign),
	hAlign(hAlign),
	position(position),
	size(size)
{
	CalcContent();
}

void UIFormat::CalcContent()
{
	content.w = size.x;
	content.h = size.y;
	block.x = topLeftPoint.x;
	block.y = topLeftPoint.y;
	content.x = topLeftPoint.x - margin.left - border.left - padding.left;
	content.y = topLeftPoint.y - margin.top - border.top - padding.top;
	block.w = size.x + margin.left + margin.right + border.left + border.right + padding.left + padding.right;
	block.h = size.y + margin.top + margin.buttom + border.top + border.buttom + padding.top + padding.buttom;
}

void UIFormat::move(iv2 delta)
{
	topLeftPoint.x += delta.x;
	topLeftPoint.y += delta.y;
	CalcContent();
}

void UIFormat::moveTo(iv2 point)
{
	topLeftPoint = point;
	CalcContent();
}
