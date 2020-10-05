#ifndef NEGATE_NODE_H
#define NEGATE_NODE_H

#include "Unary_Node.h"
#include "../command_pattern/Negation.h"

class Negate_Node : public Unary_Node
{
    public:
        Negate_Node (Node & child);
        ~Negate_Node (void);
        
        Node & child (void) const;
        int evaluate (void);
        void accept (Visitor & v);

    private:
        Negate_Node (void);
        Node* child_;
};

#include "../visitor_pattern/Visitor.h"

#endif
