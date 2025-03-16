/**
 * @author lgrumbach
 * @email github.com/xLPMG
 * @create date 15.03.2025
 * @modify date 16.03.2025
 * @desc Abstract class for game states.
 */
#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <SFML/Graphics.hpp>

namespace ed
{
    namespace states
    {
        class GameState;
    }
}

class ed::states::GameState
{
public:
    virtual ~GameState() = default;

    /**
     * @brief Updates the game state.
     */
    virtual void update() = 0;

    /**
     * @brief Handles input events for the game state.
     *
     * @param event The input event to handle.
     */
    virtual void handleInput(sf::Event& event) = 0;

    /**
     * @brief Renders the game state to the window.
     *
     * @param window The window to render the game state to.
     */
    virtual void render(sf::RenderWindow& window) = 0;
};

#endif // GAMESTATE_HPP