/**
 * @author lgrumbach
 * @email github.com/xLPMG
 * @create date 16.03.2025
 * @modify date 16.03.2025
 * @desc Header of the game state.
 */
#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "State.hpp"
#include <SFML/Graphics.hpp>
#include <memory>
#include "../Constants.hpp"

namespace ed
{
    namespace states
    {
        class GameState;
    }
}

class ed::states::GameState : public ed::states::State
{
    public:
    /**
     * @brief Constructor for the GameState class.
     */
    GameState();

    /**
     * @brief Destructor for the GameState class.
     */
    ~GameState() override = default;

    /**
     * @brief Updates the game.
     */
    void update() override;

    /**
     * @brief Handles input events for the game.
     *
     * @param event The input event to handle.
     */
    void handleInput(sf::Event &event) override;

    /**
     * @brief Renders the game to the window.
     *
     * @param window The window to render the game to.
     */
    void render(sf::RenderWindow &window) override;

    /**
     * @brief Checks if the game is finished.
     *
     * @return True if the game is finished, false otherwise.
     */
    bool isFinished() override;

    /**
     * @brief Gets the type of the next state.
     *
     * @return The next state.
     */
    ed::states::StateType getNextState() override;

private:
    bool m_isFinished = false;
};

#endif // GAMESTATE_HPP