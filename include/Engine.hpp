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
    Engine();
    void update();
    void handleInput(sf::Event& event);
    void render(sf::RenderWindow &window);

private:
    std::unique_ptr<std::stack<std::unique_ptr<ed::states::GameState>>> m_statesStack;
};

#endif // ENGINE_HPP