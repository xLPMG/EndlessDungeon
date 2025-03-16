/**
 * @author lgrumbach
 * @email github.com/xLPMG
 * @create date 16.03.2025
 * @modify date 16.03.2025
 * @desc Header of the camera class.
 */
#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <SFML/System.hpp>

namespace ed
{
    namespace graphics
    {
        class Camera;
    }
}

/**
 * @brief The camera class.
 *
 * The camera class is used to move the view of the game.
 */
class ed::graphics::Camera
{
public:
    /**
     * @brief Constructor for the Camera class.
     */
    Camera(sf::Vector2<float> position);

    /**
     * @brief Destructor for the Camera class.
     */
    ~Camera() = default;

    /**
     * @brief Moves the camera by the given amount.
     *
     * @param amount The amount to move the camera by.
     */
    void move(sf::Vector2<float> amount);

    /**
     * @brief Sets the position of the camera.
     *
     * @param position The new position of the camera.
     */
    void setPosition(sf::Vector2<float> position);

    /**
     * @brief Gets the position of the camera.
     *
     * @return The position of the camera.
     */
    sf::Vector2<float> getPosition();

private:
    //! The position of the camera.
    sf::Vector2<float> m_position = {0.0f, 0.0f};
};

#endif // CAMERA_HPP