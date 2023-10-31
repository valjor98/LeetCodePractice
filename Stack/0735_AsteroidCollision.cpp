// 735. Asteroid Collision
// stacks

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <unordered_set>

using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> stack;
    for (int asteroid : asteroids) {
        bool isDestroyed = false;
        // Check if a collision is possible
        while (!stack.empty() && asteroid < 0 && stack.back() > 0) {
            int prev = stack.back(); // the asteroid at the top of the stack
            if (abs(prev) == abs(asteroid)) {
                // Both asteroids explode
                stack.pop_back();
                isDestroyed = true;
                break;
            } else if (abs(prev) > abs(asteroid)) {
                // Only the current asteroid explodes
                isDestroyed = true;
                break;
            } else {
                // Only the asteroid at the top of the stack explodes
                stack.pop_back();
            }
        }
        if (!isDestroyed) {
            stack.push_back(asteroid);
        }
    }
    return stack;
}