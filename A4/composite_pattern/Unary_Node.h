#ifndef UNARY_NODE_H
#define UNARY_NODE_H

#include "Node.h"

class Unary_Node : public Node
{
    public:
        virtual ~Unary_Node (void) {}
        virtual Node & child (void) const = 0;
};

#endif
