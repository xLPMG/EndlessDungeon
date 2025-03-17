/**
 * @author lgrumbach
 * @email github.com/xLPMG
 * @create date 17.03.2025
 * @modify date 17.03.2025
 * @desc [description]
 */
#include "maps/Map.hpp"
#include "spdlog/spdlog.h"

ed::maps::Map::Map(int width, int height)
    : m_width(width), m_height(height), m_displayWidth(width + 2), m_displayHeight(height + 2)
{
    m_worldTiles = std::vector<std::vector<int>>(m_width, std::vector<int>(m_height, 0));
}

void ed::maps::Map::render(sf::RenderWindow &window, sf::Vector2<float> cameraPosition)
{
    
}

int ed::maps::Map::getWidth()
{
    return m_width;
}

int ed::maps::Map::getHeight()
{
    return m_height;
}

sf::Vector2i ed::maps::Map::getSize()
{
    return sf::Vector2i(m_width, m_height);
}

int ed::maps::Map::getTile(int x, int y)
{
    if (x < 0 || x >= m_width || y < 0 || y >= m_height)
    {
        spdlog::error("[WorldMap.cpp] getTile(): Tile ({}, {}) out of bounds", x, y);
        return -1;
    }
    else
    {
        return m_worldTiles[x][y];
    }
}

void ed::maps::Map::setTile(int x, int y, int tile)
{
    if (x < 0 || x >= m_width || y < 0 || y >= m_height)
    {
        spdlog::error("[WorldMap.cpp] setTile(): Tile ({}, {}) out of bounds", x, y);
        return;
    }
    else
    {
        m_worldTiles[x][y] = tile;
    }
}

void ed::maps::Map::initDisplayTiles()
{

}

void ed::maps::Map::setDisplayTiles(int x, int y)
{

}

int ed::maps::Map::calculateDisplayTile(int x, int y)
{
    return x+y;
}