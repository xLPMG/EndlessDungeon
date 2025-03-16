/**
 * @author lgrumbach
 * @email github.com/xLPMG
 * @create date 15.03.2025
 * @modify date 16.03.2025
 * @desc Endless Dungeon game engine header file.
 */
#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "states/State.hpp"
#include "states/MenuState.hpp"
#include "states/GameState.hpp"
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
     * @brief Performs a single tick of the game loop. This updates the game logic and should be called at a constant TPS.
     */
    void update();

    /**
     * @brief Handles input events for the engine.
     *
     * @param event The input event to handle.
     */
    void handleInput(sf::Event &event);

    /**
     * @brief Tells the engine to render content to the window.
     *
     * @param window The window to render to.
     */
    void render(sf::RenderWindow &window);

private:
    std::unique_ptr<std::stack<std::unique_ptr<ed::states::State>>> m_statesStack;
};

#endif // ENGINE_HPP