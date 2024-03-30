#include "Time.h"


Time::Time()
{
}

void Time::deltaTime(float& deltaTime)
{
    deltatime = clock.getElapsedTime();
    clock.restart();
    deltaTime = deltatime.asMilliseconds();
}

void Time::updateFrame(sf::Text& frameRateText, float& deltaTime)
{

    // Frame Rates 
    
    timer += deltaTime;

    if (timer >= 100.0f) {
        std::string framePrint = "Frame : " + std::to_string((int)(1000.0f / deltaTime));
        frameRateText.setString(framePrint);
        timer = 0;
    }
}
