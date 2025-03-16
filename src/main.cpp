/**
 * @author lgrumbach
 * @email github.com/xLPMG
 * @create date 15.03.2025
 * @modify date 16.03.2025
 * @desc Endless Dungeon entry point.
 */
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Constants.hpp"
#include "Engine.hpp"

/**
 * @brief Main function. Serves as the entry point of the program by opening a window and running the game loop.
 */
int main(int argc, char **argv)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode({ed::WINDOW_WIDTH, ed::WINDOW_HEIGHT}), ed::GAME_NAME + " v" + ed::GAME_VERSION);

    // Create the game engine
    ed::Engine engine;

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time timeSinceLastRender = sf::Time::Zero;

    const sf::Time timePerFrame = sf::seconds(1.0f / ed::TARGET_FPS);
    const sf::Time timePerTick = sf::seconds(1.0f / ed::TARGET_TPS);

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        while (const std::optional<sf::Event> event = window.pollEvent())
        {
            // Close window: exit
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        // Calculate elapsed time
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        timeSinceLastRender += elapsedTime;

        // Update game logic at the target TPS
        while (timeSinceLastUpdate >= timePerTick)
        {
            engine.update();
            timeSinceLastUpdate -= timePerTick;
        }

        // Render at the target FPS
        if (timeSinceLastRender >= timePerFrame)
        {
            window.clear();

            engine.render(window);
            timeSinceLastRender = sf::Time::Zero;

            window.display();
        }
    }

    return 0;
}