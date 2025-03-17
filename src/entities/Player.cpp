/**
 * @author lgrumbach
 * @email github.com/xLPMG
 * @create date 16.03.2025
 * @modify date 17.03.2025
 * @desc Implementation of the player entity.
 */
#include "entities/Player.hpp"

ed::entities::Player::Player(sf::Vector2<float> position) : m_position(position), m_direction(0.0f, 0.0f), m_speed(5.0f)
{
    m_shape = sf::RectangleShape(sf::Vector2<float>(50.0f, 100.0f));
    m_shape.setFillColor(sf::Color::Green);

    m_size = m_shape.getSize();
}

void ed::entities::Player::update()
{
    move(m_direction);
}

void ed::entities::Player::handleInput(sf::Event &event)
{
    if (const auto *keyPressed = event.getIf<sf::Event::KeyPressed>())
    {
        switch (keyPressed->code)
        {
        case sf::Keyboard::Key::W:
            m_direction.y = -1.0f;
            break;
        case sf::Keyboard::Key::A:
            m_direction.x = -1.0f;
            break;
        case sf::Keyboard::Key::S:
            m_direction.y = 1.0f;
            break;
        case sf::Keyboard::Key::D:
            m_direction.x = 1.0f;
            break;
        default:
            break;
        }
    }
    else if (const auto *keyReleased = event.getIf<sf::Event::KeyReleased>())
    {
        switch (keyReleased->code)
        {
        case sf::Keyboard::Key::W:
        case sf::Keyboard::Key::S:
            m_direction.y = 0.0f;
            break;
        case sf::Keyboard::Key::A:
        case sf::Keyboard::Key::D:
            m_direction.x = 0.0f;
            break;
        default:
            break;
        }
    }
}

void ed::entities::Player::render(sf::RenderWindow &window, sf::Vector2<float> cameraPosition)
{
    m_shape.setPosition(m_position - cameraPosition);
    window.draw(m_shape);
}

void ed::entities::Player::move(sf::Vector2<float> direction)
{
    sf::Vector2<float> moveBy = direction * m_speed;
    if (ed::notZero(moveBy.x) && ed::notZero(moveBy.y))
    {
        moveBy *= ed::DIAGONAL_SPEED;
    }
    m_position += moveBy;
}

void ed::entities::Player::setPosition(sf::Vector2<float> position)
{
    m_position = position;
}

sf::Vector2<float> ed::entities::Player::getPosition()
{
    return m_position;
}

sf::Vector2<float> ed::entities::Player::getSize()
{
    return m_size;
}

sf::FloatRect ed::entities::Player::getBoundingBox()
{
    return sf::FloatRect(m_position + sf::Vector2f(0.0f, m_size.y / 2), sf::Vector2f(m_size.x, m_size.y / 2));
}
