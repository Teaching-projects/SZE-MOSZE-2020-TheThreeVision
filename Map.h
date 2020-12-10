#include <vector>
#include <string>
#include <fstream>

class Map
{
protected:
    std::vector<std::string> map; ///It stores the map line by line.
public:
    /// Enum to map.
    enum type
    {
        Free, ///free to move
        Wall  ///not free to move 
    };

    ///Map constructor read the map from file
    Map(const std::string &Filename);
    Map() {}

    ///Simple getter to Map's Height
    int getHeight() const;
    ///Simple getter to the line's Width
    int getWidth(int line) const;
    ///Simple getter to Map 's MaxWidth
    int getMaxWidth() const;
    /// Function that returns the enum type on x,y coordinates.
    Map::type get(unsigned int x, unsigned int y) const;
    ///It returns true if the map is empty
    bool isEmpty()
    {
        if (map.empty())
            return true;
        else
            return false;
    }
    class WrongIndexException : public std::runtime_error
    {
    public:
        WrongIndexException(const std::string &errMsg) : std::runtime_error(errMsg) {}
    };
};

class MarkedMap : public Map
{

public:
    /// MarkedMap construct, what put the input parameter to the data member
    MarkedMap(const std::string &FileName/**[in] file's path or name*/);
    MarkedMap(){}
    
   /**
     * \brief get the Hero position
     * \return return with std::pair<int, int> that contains the Hero's coordinate 
     */
    std::pair<int, int> getHeroPosition() const;      
    /**
      * \brief get the Monsters position
      * \return return with std::vector<std::pair<int, int>> that contains all Monster's coordinate
      */
    std::vector<std::pair<int, int>> getMonsterPosition(char c) const;
};
