#include <vector>
#include <string>
#include <fstream>

class Map
{
protected:
    std::vector<std::string> map; ///A játék térképének a betöltése
public:
    /// Az enum térkép elemeknek.
    enum type
    {
        Free, ///bejárható út
        Wall  /// FAL
    };

    ///Map konstruktor a terkep beolvasásához
    Map(const std::string &Filename);
    Map() {}

    ///Map méretei
    int getHeight() const;
    int getWidth(int line) const;
    int getMaxWidth() const;
    /// Függvény ami visszaadja az x,y koordinátán lévő elemet.
    Map::type get(unsigned int x, unsigned int y) const;
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
    MarkedMap(const std::string &FileName);                        ///Fájlnak az elérési útvonala
    MarkedMap(){}
    std::pair<int, int> getHeroPosition() const;                       ///Hero pozícióját adja vissza
    std::vector<std::pair<int, int>> getMonsterPosition(char c) const; ///Monster pozícióját adja vissza
};
