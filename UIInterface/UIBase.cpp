#include "UIBase.h"

UIBase::UIBase(UIBase* parent, std::string title, UIFormat format)
	: parent(parent), title(title), format(format)
{
	if (parent) parent->addChild(this);
	SizeUpdate();
}

UIBase::~UIBase()
{
	for (auto i : childs) delete i;
}

void UIBase::ContentDraw(SDL_Renderer* ren)
{

}

void UIBase::Draw(SDL_Renderer* ren)
{
	if (!getProp(Properties::visible)) return;
	DrawFill(ren, format.content.getSDLRect(), bgColor);
	SDL_Rect r, c, l;
	SDL_RenderGetViewport(ren, &r);
	l = format.content.getSDLRect();
	SDL_RenderSetViewport(ren, &l);
	ContentDraw(ren);
	for (auto i : childs) i->Draw(ren);
	SDL_RenderSetViewport(ren, &r);
}

void UIBase::Update(SDL_Event* e)
{

}

void UIBase::SizeUpdate()
{
	format.CalcContent();
	switch (format.position)
	{
	case UIFormat::Positioning::absolute:
		break;
	case UIFormat::Positioning::vertical:
	{
		u32 vslice = 0;
		for (auto i : childs)
			vslice += i->getFormat().size.w;
		u32 sums = (u32)NONNEG(format.size.w - vslice) / 2;
		for (auto i : childs)
		{
			switch (format.vAlign)
			{
			case UIFormat::VerticalAlign::center:
			{
				i->getFormat().size.x = sums;
				sums += i->getFormat().size.w;
				break;
			}
			case UIFormat::VerticalAlign::buttom:
				break;
			}
		}
		break;
	}
	case UIFormat::Positioning::horizontal:
		break;
	}
}

void UIBase::setCallback(std::function<void(UIBase* elem)> callb)
{
	callback = callb;
}

std::function<void(UIBase* elem)> UIBase::getCallback()
{
	return callback;
}

UIBase* UIBase::getParent()
{
	return parent;
}

void UIBase::addChild(UIBase* child)
{
	childs.push_back(child);
}

void UIBase::delChild(UIBase* child)
{
	for (auto it = childs.begin(); it != childs.end(); ++it)
	{
		if (*it == child)
		{
			childs.erase(it);
			break;
		}
	}
}

bool UIBase::getProp(Properties prop)
{
	return propertyMask & (u32)prop;
}

void UIBase::setProp(Properties prop, bool val)
{
	propertyMask = ((u32)prop * val | (propertyMask & ~(u32)prop));
}

UIFormat& UIBase::getFormat()
{
	return format;
}

void UIBase::setFormat(UIFormat format)
{
	this->format = format;
}

std::string UIBase::getTitle()
{
	return title;
}

void UIBase::setBgColor(SDL_Color bg)
{
	bgColor = bg;
}

void UIBase::setFgColor(SDL_Color fg)
{
	fgColor = fg;
}

SDL_Color UIBase::getBgColor()
{
	return bgColor;
}

SDL_Color UIBase::getFgColor()
{
	return fgColor;
}
