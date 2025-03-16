/**
 * @author lgrumbach
 * @email github.com/xLPMG
 * @create date 16.03.2025
 * @modify date 16.03.2025
 * @desc Header of the main menu state.
 */
#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include "State.hpp"
#include <SFML/Graphics.hpp>
#include <memory>
#include "../Constants.hpp"

namespace ed
{
    namespace states
    {
        class MenuState;
    }
}

class ed::states::MenuState : public ed::states::State
{
public:
    /**
     * @brief Constructor for the MenuState class.
     */
    MenuState();

    /**
     * @brief Destructor for the MenuState class.
     */
    ~MenuState() override = default;

    /**
     * @brief Updates the menu.
     */
    void update() override;

    /**
     * @brief Handles input events for the menu.
     *
     * @param event The input event to handle.
     */
    void handleInput(sf::Event &event) override;

    /**
     * @brief Renders the menu to the window.
     *
     * @param window The window to render the menu to.
     */
    void render(sf::RenderWindow &window) override;

    /**
     * @brief Checks if the menu is finished.
     *
     * @return True if the menu is finished, false otherwise.
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

    //! The bold font for the menu.
    sf::Font m_boldFont;
    //! The regular font for the menu.
    sf::Font m_regularFont;
    //! The title text for the menu.
    std::unique_ptr<sf::Text> m_titlePtr;
    //! The play text for the menu.
    std::unique_ptr<sf::Text> m_playTextPtr;
    //! The exit text for the menu.
    std::unique_ptr<sf::Text> m_exitTextPtr;
    //! True if the play text is selected, false otherwise.
    bool m_playSelected = false;
    //! True if the exit text is selected, false otherwise.
    bool m_exitSelected = false;
    //! The next state to transition to.
    ed::states::StateType m_nextState = ed::states::StateType::None;
};

#endif // MENUSTATE_HPP
