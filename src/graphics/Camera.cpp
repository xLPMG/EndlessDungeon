/**
 * @author lgrumbach
 * @email github.com/xLPMG
 * @create date 16.03.2025
 * @modify date 16.03.2025
 * @desc Implementation of the camera class.
 */
#include "graphics/Camera.hpp"

ed::graphics::Camera::Camera(sf::Vector2<float> position)
    : m_position(position)
{
}

void ed::graphics::Camera::move(sf::Vector2<float> amount)
{
    m_position += amount;
}

void ed::graphics::Camera::setPosition(sf::Vector2<float> position)
{
    m_position = position;
}

sf::Vector2<float> ed::graphics::Camera::getPosition()
{
    return m_position;
}