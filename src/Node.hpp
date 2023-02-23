#pragma once

#include <iostream>
#include <string>
#include <memory>
#include "InstanceCounter.hpp"

class Node : public InstanceCounter
{
protected:
    Node(){}

public:
    virtual std::string print() const = 0;
};

using NodePtr = std::unique_ptr<Node>;