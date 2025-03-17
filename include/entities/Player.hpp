/**
 * @author lgrumbach
 * @email github.com/xLPMG
 * @create date 16.03.2025
 * @modify date 17.03.2025
 * @desc Header of the player entity.
 */
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "../Constants.hpp"

namespace ed
{
    namespace entities
    {
        class Player;
    }
}

/**
 * @brief The player entity class.
 *
 * The player entity class represents the player in the game.
 */
class ed::entities::Player
{
public:
    /**
     * @brief Constructor for the Player class.
     */
    Player(sf::Vector2<float> position);

    /**
     * @brief Destructor for the Player class.
     */
    ~Player() = default;

    /**
     * @brief Updates the player.
     */
    void update();

    /**
     * @brief Handles input events for the player.
     *
     * @param event The input event to handle.
     */
    void handleInput(sf::Event &event);

    /**
     * @brief Renders the player to the window.
     *
     * @param window The window to render the player to.
     */
    void render(sf::RenderWindow &window, sf::Vector2<float> cameraPosition);

    /**
     * @brief Sets the position of the player.
     */
    void setPosition(sf::Vector2<float> position);

    /**
     * @brief Gets the position of the player.
     */
    sf::Vector2<float> getPosition();

    /**
     * @brief Gets the size of the player.
     */
    sf::Vector2<float> getSize();

    /**
     * @brief Gets the bounding box of the player.
     */
    sf::FloatRect getBoundingBox();

private:
    //! The position of the player.
    sf::Vector2<float> m_position;
    //! The direction that the player is moving in.
    sf::Vector2<float> m_direction;
    //! The movement speed of the player.
    float m_speed;
    //! The size of the player.
    sf::Vector2<float> m_size;
    //! Temporary shape to represent the player.
    sf::RectangleShape m_shape;

    /**
     * @brief Moves the player by the given amount.
     *
     * @param amount The amount to move the player by.
     */
    void move(sf::Vector2<float> amount);
};

#endif // PLAYER_HPP