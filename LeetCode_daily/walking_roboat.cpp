#include<iostream>
#include<vector>
using namespace std;

class Robot {
public:
    int w, h;
    int x, y;
    int dir; // 0=East, 1=North, 2=West, 3=South
    int cycle;

    Robot(int width, int height) {
        w = width;
        h = height;
        x = 0;
        y = 0;
        dir = 0; // East
        cycle = 2 * (w + h - 2);
    }
    
    void step(int num) {
        num %= cycle;

        // Important edge case
        if (num == 0) {
            // If at origin, direction should be South after full cycle
            if (x == 0 && y == 0) dir = 3;
            return;
        }

        while (num--) {
            int nx = x, ny = y;

            if (dir == 0) nx++;       // East
            else if (dir == 1) ny++;  // North
            else if (dir == 2) nx--;  // West
            else ny--;                // South

            // If out of bounds → turn CCW
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) {
                dir = (dir + 1) % 4;
                num++; // retry this step
            } else {
                x = nx;
                y = ny;
            }
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        if (dir == 0) return "East";
        if (dir == 1) return "North";
        if (dir == 2) return "West";
        return "South";
    }
};