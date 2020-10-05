// seperated from Infix_Evaluator so that it can deal with parenthesis

#ifndef INFIX_TO_POSTFIX_H
#define INFIX_TO_POSTFIX_H

#include "../data_structures/Stack.h"

#include "../command_pattern/Addition.h"
#include "../command_pattern/Subtraction.h"
#include "../command_pattern/Multiplication.h"
#include "../command_pattern/Division.h"
#include "../command_pattern/Modulus.h"

#include <sstream>

class Infix_To_Postfix
{
    public:
        Infix_To_Postfix (void);
        ~Infix_To_Postfix (void);

        std::string convert (std::stringstream & infix );

    private:
        Binary* current_operator_;
        Stack<Binary*> operators_;
        
        std::string operators_in_stack (void);
        std::string check_stack (std::string result);
};

#endif
