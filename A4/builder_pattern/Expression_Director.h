#ifndef EXPRESSION_DIRECTOR_H
#define EXPRESSION_DIRECTOR_H

#include "Expression_Tree.h"
#include <sstream>
#include <stdexcept>

class Expression_Director
{
    public:
        Expression_Director (std::stringstream & postfix);
        ~Expression_Director (void);
        Node* get_tree (void);
    
    private:
        Expression_Director (void);

        Expression_Tree tree_;
};

#endif
