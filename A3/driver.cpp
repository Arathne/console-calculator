#include <iostream>
#include <sstream>

int main()
{   
    bool run = true;
    
    while( run )
    {
        std::cout << "?: ";
                  
        std::string input;
        std::getline( std::cin, input );
        
        if( input == "QUIT" )       
            run = false;
        else
        {
            std::stringstream ss(input);
            while( ss.good() )
            {
                std::string expression;
                getline( ss, expression, ' ' );
                std::cout << expression;
            }
            std::cout << std::endl;
        }
    }
    
    return 0;
}
