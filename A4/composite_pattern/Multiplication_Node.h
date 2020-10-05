#ifndef MULTIPLICATION_NODE_H
#define MULTIPLICATION_NODE_H

#include "Binary_Node.h"
#include "../command_pattern/Multiplication.h"

class Multiplication_Node : public Binary_Node
{
    public:  
        Multiplication_Node (Node & left, Node & right);
        ~Multiplication_Node (void);
        
        Node & right (void) const;
        Node & left (void) const;
        int evaluate (void);
        void accept (Visitor & v);

    private:
        Multiplication_Node (void);
        Node* left_;
        Node* right_;
};

#include "../visitor_pattern/Visitor.h"

#endif
