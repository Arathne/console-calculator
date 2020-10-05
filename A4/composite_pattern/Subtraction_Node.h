#ifndef SUBTRACTION_NODE_H
#define SUBTRACTION_NODE_H

#include "Binary_Node.h"
#include "../command_pattern/Subtraction.h"

class Subtraction_Node : public Binary_Node
{
    public:  
        Subtraction_Node (Node & left, Node & right);
        ~Subtraction_Node (void);
        
        Node & right (void) const;
        Node & left (void) const;
        int evaluate (void);
        void accept (Visitor & v);

    private:
        Subtraction_Node (void);
        Node* left_;
        Node* right_;
};

#include "../visitor_pattern/Visitor.h"

#endif
