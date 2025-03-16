/**
 * @author lgrumbach
 * @email github.com/xLPMG
 * @create date 15.03.2025
 * @modify date 15.03.2025
 * @desc Endless Dungeon game engine header file.
 */
#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "states/GameState.hpp"
#include "states/MenuState.hpp"
#include <SFML/Graphics.hpp>

#include <memory>
#include <stack>

namespace ed
{
    class Engine;
}

class ed::Engine
{
public:
    /**
     * @brief Constructor for the Engine class.
     */
    Engine();

    /**
     * @brief Destructor for the Engine class.
     */
    ~Engine() = default;

    /**
     * @brief Updates the engine.
     */
    void update();

    /**
     * @brief Handles input events for the engine.
     *
     * @param event The input event to handle.
     */
    void handleInput(sf::Event &event);

    /**
     * @brief Renders the engine to the window.
     *
     * @param window The window to render the engine to.
     */
    void render(sf::RenderWindow &window);

private:
    std::unique_ptr<std::stack<std::unique_ptr<ed::states::GameState>>> m_statesStack;
};

#endif // ENGINE_HPP