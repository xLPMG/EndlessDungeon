/**
 * @author lgrumbach
 * @email github.com/xLPMG
 * @create date 16.03.2025
 * @modify date 16.03.2025
 * @desc Implementation of the game state.
 */
#include "states/GameState.hpp"

ed::states::GameState::GameState()
{
    m_camera = std::make_unique<ed::graphics::Camera>(sf::Vector2<float>(0.0f, 0.0f));
    m_player = std::make_unique<ed::entities::Player>(sf::Vector2<float>(0.0f, 0.0f));
}

void ed::states::GameState::update()
{
    m_player->update();
}

void ed::states::GameState::handleInput(sf::Event &event)
{
    m_player->handleInput(event);
}

void ed::states::GameState::render(sf::RenderWindow &window)
{
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