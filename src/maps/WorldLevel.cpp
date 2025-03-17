/**
 * @author lgrumbach
 * @email github.com/xLPMG
 * @create date 17.03.2025
 * @modify date 17.03.2025
 * @desc [description]
 */
#include "maps/WorldLevel.hpp"
#include <algorithm>

ed::maps::WorldLevel::WorldLevel(int width, int height, int seed, int level)
    : m_width(width), m_height(height), m_seed(seed), m_level(level)
{
    m_groundMap = std::make_unique<ed::maps::WorldMap>(m_width, m_height);
    m_walkInFrontMap = std::make_unique<ed::maps::WorldMap>(m_width, m_height);
    m_collisionMap = std::make_unique<ed::maps::WorldMap>(m_width, m_height);
    m_walkBehindMap = std::make_unique<ed::maps::WorldMap>(m_width, m_height);
    m_decorMap = std::make_unique<ed::maps::WorldMap>(m_width, m_height);

    // example init
    for (int y = 0; y < m_height; ++y)
    {
        for (int x = 0; x < m_width; ++x)
        {
            if (y == 0 || y == m_height - 1 || x == 0 || x == m_width - 1)
            {
                m_collisionMap->setTile(x, y, 1);
            }
            else
            {
                m_collisionMap->setTile(x, y, 0);
            }
        }
    }
}

void ed::maps::WorldLevel::update()
{
}

void ed::maps::WorldLevel::handleInput(sf::Event &event)
{
}

void ed::maps::WorldLevel::render(sf::RenderWindow &window, sf::Vector2<float> cameraPosition)
{
    // example render
    for (int y = 0; y < m_height; ++y)
    {
        for (int x = 0; x < m_width; ++x)
        {
            sf::RectangleShape rect(sf::Vector2f(32, 32));
            rect.setPosition(sf::Vector2<float>(x * 32, y * 32) - cameraPosition);
            if (m_collisionMap->getTile(x, y) == 1)
            {
                rect.setFillColor(sf::Color::Red);
            }
            else
            {
                rect.setFillColor(sf::Color::White);
            }
            window.draw(rect);
        }
    }
}

bool ed::maps::WorldLevel::isColliding(sf::FloatRect boundingBox)
{
    int startX = std::max(0, static_cast<int>(boundingBox.position.x / 32));
    int startY = std::max(0, static_cast<int>(boundingBox.position.y / 32));
    int endX = std::min(m_width - 1, static_cast<int>((boundingBox.position.x + boundingBox.size.x) / 32));
    int endY = std::min(m_height - 1, static_cast<int>((boundingBox.position.y + boundingBox.size.y) / 32));

    for (int y = startY; y <= endY; ++y)
    {
        for (int x = startX; x <= endX; ++x)
        {
            if (m_collisionMap->getTile(x, y) != 0)
            {
                return true;
            }
        }
    }
    return false;
}