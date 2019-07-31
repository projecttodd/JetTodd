#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
sf::Vector2f clickPos;
enum state
{
  title, mainScreen
};
int main()
{
    while true
    {
      fstream in("out.txt");
      remoteMessage = in;
    }
    state screenState = title;
    sf::Texture backgroundTexture;
    sf::String remoteMessage;
    sf::Sprite background;
    std::string mostRecentWord = "";
    if(!backgroundTexture.loadFromFile("preview.png"))
    {
      //error
    }
    background.setTexture(backgroundTexture);
    bool messageReceived = true;
    //start button
    sf::Texture startButtonTexture;
    sf::Sprite startButton;
    startButton.setPosition(285, 110);
    if(!startButtonTexture.loadFromFile("button.png"))
    {
      //error
    }
    startButton.setTexture(startButtonTexture);
    sf::Texture mainScreenTexture;
    if(!mainScreenTexture.loadFromFile("apple.png"))
    {
      //error
    }
    std::string userInput;
    sf::Text userText;
    sf::Font font;
    float textWidth = 0;
    float textHeight = 0;
    userText.setCharacterSize(48);
    if (!font.loadFromFile("HelveticaNeue.ttf"))
    {
      //error
    }
    userText.setPosition(20,10);
    userText.setFillColor(sf::Color(110,110,110));
    userText.setFont(font);
    sf::RenderWindow window(sf::VideoMode(800, 480), "Todbot");
        while (window.isOpen())
        {
          window.clear();
          window.draw(background);
            sf::Event event;
            while (window.pollEvent(event))
            {
              if (event.type == sf::Event::Closed)
                  window.close();
                if(event.type == sf::Event::MouseButtonPressed)
                {
                  if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                    clickPos = {sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y};
                    }
                }
              }
          switch(screenState)
            {
              case title:
              window.draw(startButton);
              if (startButton.getGlobalBounds().contains(clickPos))
              {
                screenState = mainScreen;
              }
              break;

              case mainScreen:
              background.setTexture(mainScreenTexture);
              if (messageReceived == true)
              {
                for(char c : remoteMessage)
                {
                    userInput += static_cast<char>(c);
                    mostRecentWord += static_cast<char>(c);
                    userText.setString(userInput);
                    float textWidth = userText.findCharacterPos(userInput.size() - 1).x;
                    float textHeight = userText.findCharacterPos(userInput.size() - 1).y;
                    int numberCharacters = remoteMessage.getSize();
                    if (c == 32)
                      {
                        mostRecentWord.clear();
                      }
                    if (textWidth > 760 && c == 32)
                    {
                      userInput.erase(userInput.size() - 1, 1);
                      userInput += '\n';
                      mostRecentWord.clear();
                    }
                    else if (textWidth > 760)
                    {
                      userInput.erase(userInput.size() - mostRecentWord.size(), userInput.size() - 1);
                      userInput += '\n';
                      userInput += mostRecentWord;
                    }
                }
              }
              userText.setString(userInput);
              window.draw(userText);
              messageReceived = false;
            }
          window.display();
}
return(0);
}
