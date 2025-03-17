/**
 * @author lgrumbach
 * @email github.com/xLPMG
 * @create date 17.03.2025
 * @modify date 17.03.2025
 * @desc [description]
 */
#ifndef WORLD_LEVEL_HPP
#define WORLD_LEVEL_HPP

#include "WorldMap.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <memory>

namespace ed
{
    namespace maps
    {
        class WorldLevel;
    }
}

class ed::maps::WorldLevel
{
public:
    WorldLevel(int width, int height, int seed, int level);
    ~WorldLevel() = default;

    /**
     * @brief Updates the world level.
     */
    void update();

    /**
     * @brief Handles input events for the world level.
     *
     * @param event The input event to handle.
     */
    void handleInput(sf::Event &event);

    /**
     * @brief Renders the world level to the window.
     *
     * @param window The window to render the world level to.
     */
    void render(sf::RenderWindow &window, sf::Vector2<float> cameraPosition);

    /**
     * @brief Checks if a bounding box is colliding with the world level.
     *
     * @param boundingBox The bounding box to check for collision.
     * @return True if the bounding box is colliding with the world level, false otherwise.
     */
    bool isColliding(sf::FloatRect boundingBox);

private:
    int m_width;
    int m_height;
    int m_seed;
    int m_level;

    std::unique_ptr<ed::maps::WorldMap> m_groundMap;
    std::unique_ptr<ed::maps::WorldMap> m_walkInFrontMap;
    std::unique_ptr<ed::maps::WorldMap> m_collisionMap;
    std::unique_ptr<ed::maps::WorldMap> m_walkBehindMap;
    std::unique_ptr<ed::maps::WorldMap> m_decorMap;
};

#endif // WORLD_LEVEL_HPP