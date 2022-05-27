#pragma once
#include <SDL_render.h>
#include <SDL_events.h>
#include <functional>
#include <string>
#include <vector>
#include "UIFormat.h"
class UIBase
{
public:

	enum class Properties
	{
		clickable = 0x1,
		draggable = 0x2,
		scalable  = 0x4,
		visible   = 0x8,
	};

	UIBase(UIBase* parent, std::string title, UIFormat format);
	~UIBase();

	virtual void ContentDraw(SDL_Renderer* ren);
	virtual void Draw(SDL_Renderer* ren);
	virtual void Update(SDL_Event* e);
	virtual void SizeUpdate();

	void setCallback(std::function<void(UIBase* elem)> callb);
	std::function<void(UIBase* elem)> getCallback();

	UIBase* getParent();
	
	void addChild(UIBase* child);
	void delChild(UIBase* child);

	bool getProp(Properties prop);
	void setProp(Properties prop, bool val);

	UIFormat& getFormat();
	void setFormat(UIFormat format);

	std::string getTitle();

	void setBgColor(SDL_Color bg);
	void setFgColor(SDL_Color fg);
	SDL_Color getBgColor();
	SDL_Color getFgColor();
private:
	UIBase* parent = nullptr;
	std::vector<UIBase*> childs;

	u32 propertyMask = (u32)Properties::visible;
	std::function<void(UIBase* elem)> callback = nullptr;

	UIFormat format;
	std::string title;

	SDL_Color bgColor = FILLV4(255), fgColor = FILLV4(0);
};

