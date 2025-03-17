/**
 * @author lgrumbach
 * @email github.com/xLPMG
 * @create date 17.03.2025
 * @modify date 17.03.2025
 * @desc [description]
 */
#include "maps/WorldMap.hpp"
#include "spdlog/spdlog.h"

ed::maps::WorldMap::WorldMap(int width, int height)
    : m_width(width), m_height(height)
{
    m_tiles = std::vector<std::vector<int>>(m_width, std::vector<int>(m_height, 0));
}

int ed::maps::WorldMap::getWidth()
{
    return m_width;
}

int ed::maps::WorldMap::getHeight()
{
    return m_height;
}

sf::Vector2i ed::maps::WorldMap::getSize()
{
    return sf::Vector2i(m_width, m_height);
}

int ed::maps::WorldMap::getTile(int x, int y)
{
    if (x < 0 || x >= m_width || y < 0 || y >= m_height)
    {
        spdlog::error("[WorldMap.cpp] getTile(): Tile ({}, {}) out of bounds", x, y);
        return -1;
    }
    else
    {
        return m_tiles[x][y];
    }
}

void ed::maps::WorldMap::setTile(int x, int y, int tile)
{
    if (x < 0 || x >= m_width || y < 0 || y >= m_height)
    {
        spdlog::error("[WorldMap.cpp] setTile(): Tile ({}, {}) out of bounds", x, y);
        return;
    }
    else
    {
        m_tiles[x][y] = tile;
    }
}