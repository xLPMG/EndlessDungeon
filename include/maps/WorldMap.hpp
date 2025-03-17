/**
 * @author lgrumbach
 * @email github.com/xLPMG
 * @create date 17.03.2025
 * @modify date 17.03.2025
 * @desc [description]
 */
#ifndef WORLD_MAP_HPP
#define WORLD_MAP_HPP

#include <vector>
#include <SFML/System.hpp>

namespace ed
{
    namespace maps {
        class WorldMap;
    }
}

class ed::maps::WorldMap
{
public:
    WorldMap(int width, int height);
    ~WorldMap() = default;

    int getWidth();
    int getHeight();
    sf::Vector2i getSize();

    int getTile(int x, int y);
    void setTile(int x, int y, int tile);

private:
    int m_width;
    int m_height;

    std::vector<std::vector<int>> m_tiles;

};

#endif // WORLD_MAP_HPP