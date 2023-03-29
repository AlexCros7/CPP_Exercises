#pragma once

#include "../lib/lib.hpp"

#include <stdint.h>


struct RGBA
{
public:
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};

struct RGB{
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

struct Luma
{
    unsigned char gray;
};