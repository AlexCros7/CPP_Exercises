#pragma once

#include "pixels.hpp"

#include "../lib/lib.hpp"

#include <stdint.h>
#include <cstddef>
#include <functional>
#include <string>
#include <array>
#include <iostream>

template <typename P, size_t W, size_t H>
struct Image
{
public:
    Image()
    {}

    Image(const P& pix)
    {
        for (size_t j = 0; j < H; j++)
        {
            for (size_t i = 0; i < W; i++)
            {
                _pixels[j][i] = pix;
            } 
        }
    }

    Image(const std::function<P(const size_t i, const size_t j)>& functor)
    {
        for (size_t j = 0; j < H; j++)
        {
            for (size_t i = 0; i < W; i++)
            {
                _pixels[j][i] = functor(i,j);
            } 
        }
    }

    P& operator()(const size_t i, const size_t j)
    {
        return _pixels[j][i];
    }

    const P & operator()(const size_t i, const size_t j) const
    {
        return _pixels[j][i];
    }

private:
    std::array<std::array<P, W>, H> _pixels;
};

template <typename A, size_t W, size_t H>
Image<A,W,H> operator+(const Image<A,W,H>& lhs, const Image<A,W,H>& rhs)
{
    Image<A,W,H> res;
    for (size_t j = 0; j < H; j++)
    {
        for (size_t i = 0; i < W; i++)
        {
            res(i,j) = lhs(i,j) + rhs(i,j);
        } 
    }
    return res;
}