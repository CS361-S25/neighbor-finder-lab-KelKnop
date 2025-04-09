#include "emp/web/Animate.hpp"
#include "emp/web/web.hpp"

emp::web::Document doc{"target"};

class NFAnimator : public emp::web::Animate {

    // Creates the canvas (width, height, html id)
    emp::web::Canvas canvas{100, 100, "canvas"};

   public: NFAnimator() {
        doc << canvas;
        doc << "Hi!";

        for(int x = 0; x < 30; x+=10) {
            for (int y = 0; y < 30; y+=10) {
                // Draw a rectangle on the canvas filled with white and outlined in black
                // (x,y, width, height, fill color, outline color)
                canvas.Rect(x, y, 10, 10, "white", "black");
            }

        }
    }

    void FindNeighbors(int x,int y){

        // Define grid boundaries (replace with actual grid dimensions)
        int grid_width = 30;  // Example: 100 pixels wide
        int grid_height = 30; // Example: 100 pixels tall

        // (x, y) cell is black
        canvas.Rect(x, y, 10, 10, "black", "black");

        // Check and color neighbors only if they are within the grid boundaries
        if (x + 10 < grid_width) {
            canvas.Rect(x + 10, y, 10, 10, "red", "black"); // (x+1, y)
        }
        if (x - 10 >= 0) {
            canvas.Rect(x - 10, y, 10, 10, "red", "black"); // (x-1, y)
        }
        if (y + 10 < grid_height) {
            canvas.Rect(x, y + 10, 10, 10, "red", "black"); // (x, y+1)
        }
        if (y - 10 >= 0) {
            canvas.Rect(x, y - 10, 10, 10, "red", "black"); // (x, y-1)
        }
        if (x + 10 < grid_width && y + 10 < grid_height) {
            canvas.Rect(x + 10, y + 10, 10, 10, "red", "black"); // (x+1, y+1)
        }
        if (x + 10 < grid_width && y - 10 >= 0) {
            canvas.Rect(x + 10, y - 10, 10, 10, "red", "black"); // (x+1, y-1)
        }
        if (x - 10 >= 0 && y + 10 < grid_height) {
            canvas.Rect(x - 10, y + 10, 10, 10, "red", "black"); // (x-1, y+1)
        }
        if (x - 10 >= 0 && y - 10 >= 0) {
            canvas.Rect(x - 10, y - 10, 10, 10, "red", "black"); // (x-1, y-1)
        }

    }

    

};

NFAnimator animator;

int main() {
    animator.Step();
    animator.FindNeighbors(20, 20);
}