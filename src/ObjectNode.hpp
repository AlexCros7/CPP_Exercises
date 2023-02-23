#pragma once

#include "Node.hpp"
#include "NodeKind.hpp"

class ObjectNode : public Node
{
public:
    ObjectNode()
    {}

    NodeKind kind() const
    {
        return _kind;
    }

    std::string print() const
    {
        return "{}";
    }

private:
    NodeKind _kind = NodeKind::OBJECT;
};