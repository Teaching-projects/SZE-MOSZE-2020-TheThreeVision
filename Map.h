#include <vector>
#include <string>
#include <fstream>

class Map{
private:
    std::vector<std::string> map; 
public:
    
    enum type{
        Free,
        Wall 
        };

    
    Map(const std::string& Filename );  
        
        
    Map::type get( int x,  int y) const;

    class WrongIndexException : public std::runtime_error{
    public:
        WrongIndexException(const std::string& errMsg) : std::runtime_error(errMsg){}
    };
};

