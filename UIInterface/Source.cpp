#include "Application.h"

int main(int argv, char** argc)
{
	UIBase* base = new UIBase(nullptr, "Test", UIFormat({0,0,800,600}));
	UIBase* test = new UIBase(base, "Test", UIFormat({0,0,100,100}));
	test->setBgColor(COLOR::blendAlpha(COLOR::BLUE, 100));
	UIBase* test1 = new UIBase(base, "test", UIFormat({0,0,100,100}));
	test1->setBgColor(COLOR::blendAlpha(COLOR::GREEN, 100));
	base->setBgColor(COLOR::RED);
	base->getFormat().position = UIFormat::Positioning::vertical;
	Application* app = new Application(base);
	app->show();
	return 0;
}