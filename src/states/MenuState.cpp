/**
 * @author lgrumbach
 * @email github.com/xLPMG
 * @create date 16.03.2025
 * @modify date 16.03.2025
 * @desc Implementation of the game state of the main menu.
 */
#include "states/MenuState.hpp"
#include <SFML/Graphics.hpp>

ed::states::MenuState::MenuState()
{
    check(m_boldFont.openFromFile("res/fonts/Charm-Bold.ttf"), "MenuState");
    check(m_regularFont.openFromFile("res/fonts/Charm-Regular.ttf"), "MenuState");

    m_titlePtr = std::make_unique<sf::Text>(m_boldFont, GAME_NAME, 64);
    m_titlePtr->setFillColor(sf::Color::Red);

    m_playTextPtr = std::make_unique<sf::Text>(m_regularFont, "Play", 32);
    m_playTextPtr->setFillColor(sf::Color::Red);

    m_exitTextPtr = std::make_unique<sf::Text>(m_regularFont, "Exit", 32);
    m_exitTextPtr->setFillColor(sf::Color::Red);
}

void ed::states::MenuState::update()
{
    if (m_playSelected)
    {
        m_playTextPtr->setFillColor(sf::Color::White);
        m_exitTextPtr->setFillColor(sf::Color::Red);
    }
    else if (m_exitSelected)
    {
        m_playTextPtr->setFillColor(sf::Color::Red);
        m_exitTextPtr->setFillColor(sf::Color::White);
    }else {
        m_playTextPtr->setFillColor(sf::Color::Red);
        m_exitTextPtr->setFillColor(sf::Color::Red);
    }
}

void ed::states::MenuState::handleInput(sf::Event &event)
{
    if (const auto *mouseMoved = event.getIf<sf::Event::MouseMoved>())
    {
        sf::FloatRect playBounds = m_playTextPtr->getGlobalBounds();
        sf::FloatRect exitBounds = m_exitTextPtr->getGlobalBounds();

        if (playBounds.contains(static_cast<sf::Vector2f>(mouseMoved->position)))
        {
            m_playSelected = true;
            m_exitSelected = false;
        }
        else if (exitBounds.contains(static_cast<sf::Vector2f>(mouseMoved->position)))
        {
            m_playSelected = false;
            m_exitSelected = true;
        }
        else
        {
            m_playSelected = false;
            m_exitSelected = false;
        }
    }else if (const auto *mousePressed = event.getIf<sf::Event::MouseButtonPressed>())
    {
        bool isLeftClick = mousePressed->button == sf::Mouse::Button::Left;
        if(isLeftClick && m_playSelected)
        {
            m_nextState = ed::states::StateType::Game;
            m_isFinished = true;
        }
        else if(isLeftClick && m_exitSelected)
        {
            m_nextState = ed::states::StateType::None;
            m_isFinished = true;
        }
    }
    
}

void ed::states::MenuState::render(sf::RenderWindow &window)
{
    sf::Vector2u windowSize = window.getSize();
    const float windowWidth = static_cast<float>(windowSize.x);
    const float windowHeight = static_cast<float>(windowSize.y);

    // Center the title
    sf::FloatRect titleBounds = m_titlePtr->getLocalBounds();
    m_titlePtr->setOrigin({titleBounds.size.x / 2, titleBounds.size.y / 2});
    m_titlePtr->setPosition({windowWidth / 2, windowHeight / 4});

    // Center the play text
    sf::FloatRect playBounds = m_playTextPtr->getLocalBounds();
    m_playTextPtr->setOrigin({playBounds.size.x / 2, playBounds.size.y / 2});
    m_playTextPtr->setPosition({windowWidth / 2, windowHeight / 2});

    // Center the exit text
    sf::FloatRect exitBounds = m_exitTextPtr->getLocalBounds();
    m_exitTextPtr->setOrigin({exitBounds.size.x / 2, exitBounds.size.y / 2});
    m_exitTextPtr->setPosition({windowWidth / 2, windowHeight / 2 + 50});

    // Draw the text
    window.draw(*m_titlePtr);
    window.draw(*m_playTextPtr);
    window.draw(*m_exitTextPtr);
}

bool ed::states::MenuState::isFinished()
{
    return m_isFinished;
}

ed::states::StateType ed::states::MenuState::getNextState() const
{
    return m_nextState;
}