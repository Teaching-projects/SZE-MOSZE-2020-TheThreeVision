#include <vector>
#include <string>
#include <fstream>

class Map{
private:
    std::vector<std::string> map; ///A játék térképének a betöltése
public:
    /// Az enum térkép elemeknek.
    enum type{ 
        Free, ///bejárható út
        Wall  /// FAL
        };

    ///Map konstruktor a terkep beolvasásához
    Map(const std::string& Filename );  
    Map(){}

    ///Map méretei
    int getHeight();
    int getWidth(int line) const;    
    /// Függvény ami visszaadja az x,y koordinátán lévő elemet.    
    Map::type get( unsigned int x, unsigned int y) const;
    bool isEmpty(){
        if (map.empty()) return true;
        else return false;
    }
    class WrongIndexException : public std::runtime_error{
    public:
        WrongIndexException(const std::string& errMsg) : std::runtime_error(errMsg){}
    };
};

