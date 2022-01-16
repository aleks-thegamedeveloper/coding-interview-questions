// Consider an enemy at EnemyLocation facing the EnemyDirection; FoV specified.
// The player character is at PlayerLocation.
// Write a VisualCheck function that checks if the Enemy Character is able to see the Player Character.

#include <iostream>
#include "vec.h"

// dot(a,b) = |a|*|b|*cos(ab)

bool VisualCheck(vec enemyLocation, vec enemyForward, float enemyFoV, vec playerLocation)
{
    const vec enemyPlayerVector = playerLocation - enemyLocation;

    const float k_epsilon = 1e-9f;
    if (magnitude(enemyPlayerVector) <= k_epsilon)
    {
        return false;
    }

    const vec enemyPlayerDirection = normalize(enemyPlayerVector);
    const vec enemyDirection = normalize(enemyForward);

    const float enemyPlayerDot = dot(enemyDirection, enemyPlayerDirection);
    const float enemyPlayerAngleRad = acosf(enemyPlayerDot);
    const float enemyPlayerAngleDeg = enemyPlayerAngleRad * 180.f / 3.14f;

    return enemyPlayerAngleDeg <= enemyFoV / 2.f;
}

int main()
{
    bool res = VisualCheck(
        vec{ 0.f, 0.f, 0.f },
        vec{ 1.f, 0.f, 0.f },
        45.f,
        vec{ 5.f, 1.f, 0.f }
    );

    if (res)
    {
        std::cout << "Visible!\n";
    }
    else
    {
        std::cout << "Not Visible!\n";
    }

    res = VisualCheck(
        vec{ 0.f, 0.f, 0.f },
        vec{ 1.f, 0.f, 0.f },
        45.f,
        vec{ 5.f, 5.f, 0.f }
    );

    if (res)
    {
        std::cout << "Visible!\n";
    }
    else
    {
        std::cout << "Not Visible!\n";
    }
}