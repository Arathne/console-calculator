#ifndef MODULUS_NODE_H
#define MODULUS_NODE_H

#include "Binary_Node.h"
#include "../command_pattern/Modulus.h"

class Modulus_Node : public Binary_Node
{
    public:  
        Modulus_Node (Node & left, Node & right);
        ~Modulus_Node (void);
        
        Node & right (void) const;
        Node & left (void) const;
        int evaluate (void);
        void accept (Visitor & v);

    private:
        Modulus_Node (void);
        Node* left_;
        Node* right_;
};

#include "../visitor_pattern/Visitor.h"

#endif
