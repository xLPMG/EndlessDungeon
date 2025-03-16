/**
 * @author lgrumbach
 * @email github.com/xLPMG
 * @create date 15.03.2025
 * @modify date 16.03.2025
 * @desc Endless Dungeon game engine implementation file.
 */
#include "Engine.hpp"
#include <iostream>

ed::Engine::Engine()
{
    m_statesStack = std::make_unique<std::stack<std::unique_ptr<ed::states::State>>>();
    m_statesStack->push(std::make_unique<ed::states::MenuState>());
}

void ed::Engine::update()
{
    // Update the current state
    if (!m_statesStack->empty())
    {
        m_statesStack->top()->update();

        // If the current state is finished, pop it off the stack
        if (m_statesStack->top()->isFinished())
        {
            ed::states::StateType nextState = m_statesStack->top()->getNextState();
            m_statesStack->pop();

            switch (nextState)
            {
                case ed::states::StateType::Menu:
                    m_statesStack->push(std::make_unique<ed::states::MenuState>());
                    break;
                case ed::states::StateType::Game:
                    m_statesStack->push(std::make_unique<ed::states::GameState>());
                    break;
                case ed::states::StateType::None:
                default:
                    break;
            }
        }
    }
}

void ed::Engine::handleInput(sf::Event &event)
{
    // Handle input for the current game state
    if (!m_statesStack->empty())
    {
        m_statesStack->top()->handleInput(event);
    }
}

void ed::Engine::render(sf::RenderWindow &window)
{
    // Render the current game state
    if (!m_statesStack->empty())
    {
        m_statesStack->top()->render(window);
    }else{
        window.close();
    }
}