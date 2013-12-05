#ifndef INC_RGB_H
#define INC_RGB_H



#if defined(LEDLIB_RBG_ORDER)
struct RGB { unsigned char r; unsigned char b; unsigned char g; };
#elif defined(LEDLIB_BRG_ORDER)
struct RGB { unsigned char b; unsigned char r; unsigned char g; };
#elif defined(LEDLIB_BGR_ORDER)
struct RGB { unsigned char b; unsigned char g; unsigned char r; };
#elif defined(LEDLIB_GBR_ORDER)
struct RGB { unsigned char g; unsigned char b; unsigned char r; };
#elif defined(LEDLIB_GRB_ORDER)
struct RGB { unsigned char g; unsigned char r; unsigned char b; };
#else
// default to rgb
struct RGB { unsigned char r; unsigned char g; unsigned char b; };
#endif

inline RGB cRGB(unsigned char r, unsigned char g, unsigned char b) {
	RGB v;
	v.r = r; v.g = g; v.b = b;
	return v;
}

extern RGB EMPTY_COLOR;


#endif