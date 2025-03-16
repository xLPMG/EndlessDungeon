/**
 * @author lgrumbach
 * @email github.com/xLPMG
 * @create date 16.03.2025
 * @modify date 16.03.2025
 * @desc Header for the game state of the main menu.
 */
#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include "GameState.hpp"
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

class ed::states::MenuState : public ed::states::GameState
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

private:
    sf::Font m_boldFont;
    sf::Font m_regularFont;
    std::unique_ptr<sf::Text> m_titlePtr;
    std::unique_ptr<sf::Text> m_playTextPtr;
    std::unique_ptr<sf::Text> m_exitTextPtr;

    bool m_playSelected = false;
    bool m_exitSelected = false;
};

#endif // MENUSTATE_HPP
