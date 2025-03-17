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
#include "spdlog/spdlog.h"

/**
 * @brief Entry point of the program. Opens a window and runs the main loop.
 */
int main()
{
    // Format logger
    spdlog::set_pattern("[%H:%M:%S %z] [%^%l%$] %v");

    // Create the main window
    sf::RenderWindow window(sf::VideoMode({ed::WINDOW_WIDTH, ed::WINDOW_HEIGHT}), ed::GAME_NAME + " v" + ed::GAME_VERSION);

    // Create the game engine
    ed::Engine engine;

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time timeSinceLastRender = sf::Time::Zero;

    const sf::Time timePerFrame = sf::seconds(1.0f / ed::TARGET_FPS);
    const sf::Time timePerTick = sf::seconds(1.0f / ed::TARGET_TPS);

    spdlog::info("Starting game loop");

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        while (std::optional<sf::Event> eventOpt = window.pollEvent())
        {
            if (eventOpt.has_value())
            {
                sf::Event event = std::exchange(eventOpt, std::nullopt).value();

                if (event.is<sf::Event::Closed>())
                {
                    window.close();
                }
                else
                {
                    engine.handleInput(event);
                }
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