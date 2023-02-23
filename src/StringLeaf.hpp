#pragma once

#include "Leaf.hpp"
#include "NodeKind.hpp"

class StringLeaf : public Leaf
{
public:
    StringLeaf(const std::string& data)
        : _data { data }
    {}

    NodeKind kind() const
    {
        return _kind;
    }

    std::string print() const
    {
        return "\"" + _data + "\"";
    }

    std::string data() const
    {
        return _data;
    }

private:
    NodeKind _kind = NodeKind::STRING;
    std::string _data;
};