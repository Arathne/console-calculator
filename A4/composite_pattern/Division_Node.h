#ifndef DIVISION_NODE_H
#define DIVISION_NODE_H

#include "Binary_Node.h"
#include "../command_pattern/Division.h"

class Division_Node : public Binary_Node
{
    public:  
        Division_Node (Node & left, Node & right);
        ~Division_Node (void);
        
        Node & right (void) const;
        Node & left (void) const;
        int evaluate (void);
        void accept (Visitor & v);

    private:
        Division_Node (void);
        Node* left_;
        Node* right_;
};

#include "../visitor_pattern/Visitor.h"

#endif
