#ifndef NODE_H
#define NODE_H

class Visitor;

class Node
{
    public:
        virtual ~Node (void) {}
        virtual int evaluate (void) = 0;
        virtual void accept (Visitor & v) = 0;
};

#endif
