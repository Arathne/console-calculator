#ifndef NUMBER_NODE_H
#define NUMBER_NODE_H

#include "Node.h"

class Number_Node : public Node
{
    public:
        Number_Node (int number);
        ~Number_Node (void);
        
        int evaluate (void);
        void accept (Visitor & v);

    private:
        Number_Node (void);
        int number_;
};

#include "../visitor_pattern/Visitor.h"

#endif
