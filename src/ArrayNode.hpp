#pragma once

#include "Node.hpp"
#include "NodeKind.hpp"

class ArrayNode : public Node
{
public:
    ArrayNode()
    {}

    NodeKind kind() const
    {
        return _kind;
    }

    std::string print() const
    {
        return "[]";
    }

private:
    NodeKind _kind = NodeKind::ARRAY;
};