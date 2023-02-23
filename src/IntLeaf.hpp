#pragma once

#include "Leaf.hpp"
#include "NodeKind.hpp"

class IntLeaf : public Leaf
{
public:
    IntLeaf(int data)
        : _data { data }
    {}

    NodeKind kind() const
    {
        return _kind;
    }

    std::string print() const
    {
        return std::to_string(_data);
    }

    int data() const
    {
        return _data;
    }

private:
    NodeKind _kind = NodeKind::INT;
    int _data;
};