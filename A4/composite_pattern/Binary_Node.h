#ifndef BINARY_NODE_H
#define BINARY_NODE_H

#include "Node.h"

class Binary_Node : public Node
{
    public:
        virtual ~Binary_Node (void) {};
        virtual Node & left (void) const = 0;
        virtual Node & right (void) const = 0;
};

#endif
