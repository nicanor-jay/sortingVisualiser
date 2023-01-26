#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <random>
#include <iostream>
#include <stdlib.h> 

const int screenWidth = 1000;
const int screenHeight = 400;

const int numBars = 100;
const int barWidth = screenWidth / numBars;

void populateBarArray(int barArray[]) {
    // Populate array list for bar heights
    for (int i = 0; i < numBars; i++) {
        barArray[i] = (rand() % screenHeight) + 1;
        std::cout << barArray[i] << '\n';
    }
}

void drawBarArray(sf::RenderWindow &window, int barArray[]) {
    window.clear(sf::Color::Black);
    for (int k = 0; k < numBars; k++)
    {
        sf::RectangleShape rect(sf::Vector2f(barWidth, barArray[k]));
        rect.setFillColor(sf::Color::White);
        rect.setPosition(k * barWidth, screenHeight - barArray[k]);
        window.draw(rect);
    }
    window.display();
}

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Sorting Visualiser");

    int temp;
    bool swap = false;
    bool sorted = false;

    int barArray[numBars] = {};

    populateBarArray(barArray);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        //drawBarArray(window, barArray);

        // Bubblesort Code
        while (sorted ==false) {
            for (int i = 0; i < numBars-1; i++)
            {
                swap = false;

                for (int j = 0; j < numBars - i - 1; j++)
                {
                    if (barArray[j] >= barArray[j + 1])
                    {
                        //Swap
                        temp = barArray[j];
                        barArray[j] = barArray[j + 1];
                        barArray[j + 1] = temp;

                        swap = true;

                        // Draw bars
                        drawBarArray(window, barArray);
                    }
                }

                if (swap == false)
                {
                    sorted = true;
                    
                }
            }
        }
        
        //window.display();
    }
    return 0;
}