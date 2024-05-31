#include <iostream>
#include <cstdlib>
#include <ctime>
#include "snake.h"
#include "board.h"



Snake::Snake(Color color, int turn_left_key, int turn_right_key, std::string snakeColor)
    : color(color), turn_left_key(turn_left_key), turn_right_key(turn_right_key), snakeColor(snakeColor)
{
    srand(time(NULL));
    reset();
}

void Snake::reset() {
    angle = static_cast<float>((std::rand() % 360) + 1);

    position = {
        static_cast<float>(std::rand() % (1300 - 2 * margin)) + margin,
        static_cast<float>(std::rand() % (850 - 2 * margin)) + margin
    };


    // Make sure all trails and gaps are cleared
    trail.clear();
    trail.push_back(position);

    makingGap = false;
    gapCounter = 0;

    is_active = true;

    // Initial movement to avoid infinite self-collision
    for (int i = 0; i < 21; ++i) {
            move();
            trail.push_back(position);
        }
}


// GETTERS
Color Snake::get_color() const{
    return color;
}

std::string Snake::get_color_str() const{
   return snakeColor;
}

unsigned Snake::get_angle() const{
    return angle;
}

Vector2 Snake::get_position() const{
   return position;
}

unsigned Snake::get_turn_right_key() const{
    return turn_right_key;
}

unsigned Snake::get_turn_left_key() const{
    return turn_left_key;
}

std::vector<Vector2> Snake::get_trail() const {
    return trail;
}


// DRAW

void Snake::draw() {
    for (const Vector2& point : trail) {
        DrawCircleV(point, 3, color);
    }

    DrawCircleV(position, 3, color);
}

// MOVEMENT
void Snake::move() {
    position.x += cosf(DEG2RAD * angle) * speed;
    position.y += sinf(DEG2RAD * angle) * speed;
}

void Snake::update() {
    if (!is_active) return;

    if (IsKeyDown(turn_left_key)) {
        angle -= 3.0f; // Turn left
    }
    if (IsKeyDown(turn_right_key)) {
        angle += 3.0f; // Turn right
    }

    // Move the snake in the direction of the current angle
    move();

    // Generate random gaps in the trail
    if (!makingGap && (std::rand() % 100) < 2)
    {
        makingGap = true;
        gapCounter = 10 + (std::rand() % 4);
    }

    // Update the trail
    if (makingGap)
    {
        gapCounter--;
        if (gapCounter <= 0)
        {
            makingGap = false;
        }
    }
    else
    {
        trail.push_back(position);
    }

}

bool Snake::check_self_collision() const {
    const Vector2& head = get_position();
    size_t positionsIgnored = 20;
    for (size_t i = 0; i < trail.size() - positionsIgnored; ++i) { // Ignore the last 10 positions to avoid immediate collision with itself
        if (CheckCollisionPointCircle(head, trail[i], 3)) {
            std::cout << "Self collision detected at (" << trail[i].x << ", " << trail[i].y << ")" << std::endl;
            return true;
        }
    }
    return false;
}

bool Snake::check_collision_with_walls(int screen_width, int screen_height) const {
    const Vector2& head = get_position();
    return head.x < 0 || head.y < 0 || head.x > screen_width || head.y > screen_height;
}

bool Snake::check_collision_with_others(const std::vector<Snake>& snakes) const {
    const Vector2& head = get_position();
    for (const Snake& other : snakes) {
        if (&other != this) {
            const auto& trail = other.get_trail();
            for (const Vector2& point : trail) {
                if (CheckCollisionPointCircle(head, point, 3)) {
                    return true;
                }
            }
        }
    }
    return false;
}

void Snake::draw_initial_direction_arrow() const {
    Vector2 arrowEnd = {
        position.x + cosf(DEG2RAD * angle) * 20,
        position.y + sinf(DEG2RAD * angle) * 20
    };

    Vector2 arrowLine = {
        position.x + cosf(DEG2RAD * angle) * 10,
        position.y + sinf(DEG2RAD * angle) * 10
    };
    DrawLineEx(position, arrowLine, 3, color);

    // Calculate the points for the arrowhead
    float arrowAngle1 = angle + 150;
    float arrowAngle2 = angle - 150;
    Vector2 arrowLeft = {
        arrowEnd.x + cosf(DEG2RAD * arrowAngle1) * 12,
        arrowEnd.y + sinf(DEG2RAD * arrowAngle1) * 12
    };
    Vector2 arrowRight = {
        arrowEnd.x + cosf(DEG2RAD * arrowAngle2) * 12,
        arrowEnd.y + sinf(DEG2RAD * arrowAngle2) * 12
    };

    // Draw the arrowhead
    DrawTriangle(arrowEnd, arrowRight, arrowLeft, color);
}
