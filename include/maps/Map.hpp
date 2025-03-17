/**
 * @author lgrumbach
 * @email github.com/xLPMG
 * @create date 17.03.2025
 * @modify date 17.03.2025
 * @desc Header file for the Map object.
 */
#ifndef MAP_HPP
#define MAP_HPP

#include <vector>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

namespace ed
{
    namespace maps
    {
        class Map;
    }
}

/**
 * @brief Map object that represents a 2D grid of tiles.
 */
class ed::maps::Map
{
public:
    /**
     * @brief Constructor for the Map object.
     */
    Map(int width, int height);

    /**
     * @brief Destructor for the Map object.
     */
    ~Map() = default;

    /**
     * @brief Renders the map to the window.
     */
    void render(sf::RenderWindow &window, sf::Vector2<float> cameraPosition);

    /**
     * @brief Returns the width of the map in tiles.
     */
    int getWidth();

    /**
     * @brief Returns the height of the map in tiles.
     */
    int getHeight();

    /**
     * @brief Returns the size of the map in tiles.
     */
    sf::Vector2i getSize();

    /**
     * @brief Returns the tile id at the given position.
     */
    int getTile(int x, int y);

    /**
     * @brief Sets the tile id at the given position.
     */
    void setTile(int x, int y, int tileId);

private:
    //! Width of the map in tiles.
    int m_width;
    //! Height of the map in tiles.
    int m_height;
    //! Width of the display map in tiles.
    int m_displayWidth;
    //! Height of the display map in tiles.
    int m_displayHeight;

    //! Offsets for the display tiles.
    const std::array<sf::Vector2i, 4> WORLD_TILE_DISPLAY_OFFSETS = {
        sf::Vector2i(0, 0),
        sf::Vector2i(1, 0),
        sf::Vector2i(0, 1),
        sf::Vector2i(1, 1)};

    //! 2D vector of tile ids for the world map.
    std::vector<std::vector<int>> m_worldTiles;
    //! 2D vector of tile ids for the display map.
    std::vector<std::vector<int>> m_displayTiles;

    /**
     * @brief Initializes the display tiles.
     */
    /*TODO: make sure to not always set all 4 display tiles for 
          each world tile, because the top/left tiles might 
          have been set already by the previous world tile.       
    */
    void initDisplayTiles();

    /**
     * @brief Sets the display tile ids for the given world tile position.
     */
    void setDisplayTiles(int x, int y);

    /**
     * @brief Calculates the display tile id for the given world tile position.
     */
    int calculateDisplayTile(int x, int y);
};

#endif // MAP_HPP