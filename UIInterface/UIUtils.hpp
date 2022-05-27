#pragma once
#include <SDL_rect.h>
#include <SDL_render.h>
#include <cmath>

#define ZEROV4 {0,0,0,0}
#define ZEROV3 {0,0,0}
#define ZEROV2 {0,0}

#define FILLV4(data) {data,data,data,data}
#define FILLV3(data) {data,data,data}
#define FILLV2(data) {data,data}

#define SDLCLRCONV(color) color.r, color.g, color.b, color.a
#define NONNEG(a) std::max((f64)(a), (f64)(0))

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

typedef float f32;
typedef double f64;

template<class T>
struct vec4
{
	union
	{
		T x, r, top;
	};
	union
	{
		T y, g, right;
	};
	union
	{
		T w, b, buttom;
	};
	union
	{
		T h, a, left;
	};

	const SDL_Rect getSDLRect() const;
	const SDL_Color getSDLColor() const;
};

template<class T>
struct vec3
{
	union
	{
		T x, r;
	};
	union
	{
		T y, g;
	};
	union
	{
		T z, b;
	};
};

template<class T>
struct vec2
{
	union
	{
		T x;
	};
	union
	{
		T y;
	};

	const SDL_Point getSDLPoint();
};

template<class T>
inline const SDL_Rect vec4<T>::getSDLRect() const
{
	return { x,y,w,h };
}

template<class T>
inline const SDL_Color vec4<T>::getSDLColor() const
{
	return { r,g,b,a };
}

template<class T>
inline const SDL_Point vec2<T>::getSDLPoint()
{
	return SDL_Point(x,y);
}

typedef vec4<u32> uv4;
typedef vec4<i32> iv4;
typedef vec3<u32> uv3;
typedef vec3<i32> iv3;
typedef vec2<u32> uv2;
typedef vec2<i32> iv2;

inline void setDrawColor(SDL_Renderer* ren, SDL_Color c)
{
	SDL_SetRenderDrawColor(ren, SDLCLRCONV(c));
}
inline void DrawFill(SDL_Renderer* ren, SDL_Rect r)
{
	SDL_RenderFillRect(ren, &r);
}
inline void DrawFill(SDL_Renderer* ren, SDL_Rect r, SDL_Color c)
{
	setDrawColor(ren, c);
	DrawFill(ren, r);
}

namespace COLOR
{
	inline SDL_Color blendAlpha(SDL_Color col, u8 val)
{
	col.a = val;
	return col;
}
	static SDL_Color RED = { 255,0,0,255 };
	static SDL_Color GREEN = { 0,255,0,255 };
	static SDL_Color BLUE = { 0,0,255,255 };
	static SDL_Color WHITE = { 255,255,255,255 };
	static SDL_Color BLACK = { 0,0,0,255 };
}