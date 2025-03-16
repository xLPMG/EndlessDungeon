/**
 * @author lgrumbach
 * @email github.com/xLPMG
 * @create date 15.03.2025
 * @modify date 15.03.2025
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

    virtual void update(float deltaTime) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
};

#endif // GAMESTATE_HPP