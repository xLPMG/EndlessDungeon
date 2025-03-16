/**
 * @author lgrumbach
 * @email github.com/xLPMG
 * @create date 15.03.2025
 * @modify date 15.03.2025
 * @desc Endless Dungeon game engine implementation file.
 */
#include "Engine.hpp"
#include <iostream>

/**
 * @brief Constructor for the Engine class.
 */
ed::Engine::Engine()
{
    m_statesStack = std::make_unique<std::stack<std::unique_ptr<ed::states::GameState>>>();
}

/**
 * @brief Performs a single tick of the game loop. This updates the game logic and should be called at a constant TPS.
 */
void ed::Engine::update()
{
}

/**
 * @brief Draws the game to the window.
 *
 * @param window The window to render the game to.
 */
void ed::Engine::render(sf::RenderWindow &window)
{
    // Render the current game state
    if (!m_statesStack->empty())
    {
        m_statesStack->top()->render(window);
    }
}