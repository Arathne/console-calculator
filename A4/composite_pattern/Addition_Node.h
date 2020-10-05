#ifndef ADDITION_NODE_H
#define ADDITION_NODE_H

#include "Binary_Node.h"
#include "../command_pattern/Addition.h"

class Addition_Node : public Binary_Node
{
    public:  
        Addition_Node (Node & left, Node & right);
        ~Addition_Node (void);
        
        Node & right (void) const;
        Node & left (void) const;
        int evaluate (void);
        void accept (Visitor & v);

    private:
        Addition_Node (void);
        Node* left_;
        Node* right_;
};

#include "../visitor_pattern/Visitor.h"

#endif
