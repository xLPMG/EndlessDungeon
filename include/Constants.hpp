/**
 * @author lgrumbach
 * @email github.com/xLPMG
 * @create date 15.03.2025
 * @modify date 16.03.2025
 * @desc Constants used throughout the game.
 */
#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <string>

namespace ed
{

    //! The name of the game.
    std::string const GAME_NAME = "Endless Dungeon";

    //! The version of the game.
    std::string const GAME_VERSION = "0.1.0";

    //! The width of the window.
    unsigned int const WINDOW_WIDTH = 1000;

    //! The height of the window.
    unsigned int const WINDOW_HEIGHT = 600;

    //! The target frames per second.
    unsigned int const TARGET_FPS = 60;

    //! The target ticks per second.
    unsigned int const TARGET_TPS = 60;

    //! Used for normalizing the diagonal movement speed.
    const float DIAGONAL_SPEED = 0.7071;

    unsigned int const TILE_WIDTH = 32;

    unsigned int const TILE_HEIGHT = 32;

    /**
     * @brief Checks a condition and throws a runtime error if it is false.
     *
     * @param condition The condition to check.
     * @param className The name of the class where the condition failed.
     */
    inline void check(bool condition, const std::string &className)
    {
        if (!condition)
        {
            throw std::runtime_error("Condition failed in class: " + className);
        }
    }

    /**
     * @brief Checks if a float is not zero.
     */
    inline bool notZero(float value)
    {
        const float epsilon = 0.0001f;
        return value > epsilon || value < -epsilon;
    }
}

#endif // CONSTANTS_HPP