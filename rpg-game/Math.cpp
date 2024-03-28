#include "Math.h"
#include<iostream>

sf::Vector2f Math::NormalizedVector(sf::Vector2f vector)
{
    double Magintude = sqrt(vector.x * vector.x + vector.y * vector.y);

    sf::Vector2f Normalized;

    Normalized.x = vector.x / Magintude;
    Normalized.y = vector.y / Magintude;

    return Normalized;
}
/*
        rec1 left > rec2 right &&
        rec2 left > rec1 right &&

        rec1 top > rec2 bottom &&
        rec2 top > rec1 bottom

rec1 Right =  rec1 x axis + widh of the rec1

rec1 bottom = rec1 y axis + higth of the rec1

*/

bool Math::DidItCollied(sf::FloatRect rec1, sf::FloatRect rec2)
{
    if ((rec1.left + rec1.width) > rec2.left &&
        (rec2.left + rec1.width)  > rec1.left &&
        rec1.top < (rec2.top + rec2.height) &&
        rec2.top < (rec1.top + rec1.height) ) 
        return true;
   
    return false;
}
