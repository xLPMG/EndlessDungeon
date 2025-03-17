/**
 * @author lgrumbach
 * @email github.com/xLPMG
 * @create date 16.03.2025
 * @modify date 17.03.2025
 * @desc Implementation of the game state.
 */
#include "states/GameState.hpp"

ed::states::GameState::GameState()
{
    m_camera = std::make_unique<ed::graphics::Camera>(sf::Vector2<float>(0.0f, 0.0f));
    m_player = std::make_unique<ed::entities::Player>(sf::Vector2<float>(32.0f, 32.0f));
    m_worldLevel = std::make_unique<ed::maps::WorldLevel>(10, 10, 1234, 0);
}

void ed::states::GameState::update()
{
    sf::Vector2<float> playerPosition = m_player->getPosition();
    m_player->update();
    if (m_worldLevel->isColliding(m_player->getBoundingBox()))
    {
        m_player->setPosition(playerPosition);
    }
    m_camera->setPosition(m_player->getPosition() - sf::Vector2<float>(WINDOW_WIDTH, WINDOW_HEIGHT) / 2.0f + (m_player->getSize() / 2.0f));
}

void ed::states::GameState::handleInput(sf::Event &event)
{
    m_player->handleInput(event);
}

void ed::states::GameState::render(sf::RenderWindow &window)
{
    m_worldLevel->render(window, m_camera->getPosition());
    m_player->render(window, m_camera->getPosition());
}

bool ed::states::GameState::isFinished()
{
    return false;
}

ed::states::StateType ed::states::GameState::getNextState()
{
    return ed::states::StateType::None;
}