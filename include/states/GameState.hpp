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
#include "../Constants.hpp"
#include "../graphics/Camera.hpp"
#include "../entities/Player.hpp"

#include <SFML/Graphics.hpp>
#include <memory>

namespace ed
{
    namespace states
    {
        class GameState;
    }
}

/**
 * @brief The game state class.
 *
 * The game state class represents the game state in the game. 
 * It is responsible for updating, rendering, and handling input for the game.
 */
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
    //! True if the game is finished, false otherwise.
    bool m_isFinished = false;
    //! The camera for the game.
    std::unique_ptr<ed::graphics::Camera> m_camera;
    //! The player for the game.
    std::unique_ptr<ed::entities::Player> m_player;
};

#endif // GAMESTATE_HPP