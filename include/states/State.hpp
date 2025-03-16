/**
 * @author lgrumbach
 * @email github.com/xLPMG
 * @create date 15.03.2025
 * @modify date 16.03.2025
 * @desc Abstract class for states.
 */
#ifndef STATE_HPP
#define STATE_HPP

#include <SFML/Graphics.hpp>

namespace ed
{
    namespace states
    {
        enum class StateType
        {
            None,
            Menu,
            Game
        };

        class State;
    }
}

class ed::states::State
{
public:
    virtual ~State() = default;

    /**
     * @brief Updates the state.
     */
    virtual void update() = 0;

    /**
     * @brief Handles input events for the state.
     *
     * @param event The input event to handle.
     */
    virtual void handleInput(sf::Event& event) = 0;

    /**
     * @brief Renders the state to the window.
     *
     * @param window The window to render the game state to.
     */
    virtual void render(sf::RenderWindow& window) = 0;

    /**
     * @brief Checks if the state is finished.
     *
     * @return True if the state is finished, false otherwise.
     */
    virtual bool isFinished() = 0;

    /**
     * @brief Gets the next state type.
     *
     * @return The next state type.
     */
    virtual StateType getNextState() const = 0;
};

#endif // STATE_HPP