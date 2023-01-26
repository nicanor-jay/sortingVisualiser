#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <random>
#include <iostream>
#include <stdlib.h> 

const int screenWidth = 1000;
const int screenHeight = 400;

const int numBars = 100;
const int barWidth = screenWidth / numBars;

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Sorting Visualiser");

    int temp;
    bool swap = false;

    // Populate array list for bar heights
    int barArray[numBars] = {};
    for (int i = 0; i < numBars; i++) {
        barArray[i] = (rand() % screenHeight) + 1;
        std::cout << barArray[i] << '\n';
    }

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

        // Scrolls past
        //temp = barArray[0];
        //for (int i = 0; i < numBars-1; i++)
        //{
        //    barArray[i] = barArray[i + 1];
        //}
        //barArray[99] = temp;
        //sf::sleep(sf::microseconds(5000));

        // clear the window with black color
        window.clear(sf::Color::Black);

        // Draw bars
        for (int i = 0; i < numBars; i++)
        {
            sf::RectangleShape rect(sf::Vector2f(barWidth, barArray[i]));
            rect.setPosition(i * barWidth, screenHeight - barArray[i]);
            window.draw(rect);
        }

        // Bubblesort Code
        for (int i = 0; i < numBars; i++)
        {
            swap = false;

            for (int j = 0; j < numBars - i - 1; j++)
            {
                if (barArray[j] > barArray[j + 1])
                {
                    //Swap
                    temp = barArray[j];
                    barArray[j] = barArray[j + 1];
                    barArray[j + 1] = temp;

                    swap = true;
                    
                    // Clear screen to update new bars
                    window.clear(sf::Color::Black);
                    // Draw bars
                    for (int k = 0; k < numBars; k++)
                    {
                        sf::RectangleShape rect(sf::Vector2f(barWidth, barArray[k]));
                        rect.setPosition(k * barWidth, screenHeight - barArray[k]);
                        window.draw(rect);
                    }
                    sf::sleep(sf::milliseconds(1));
                    window.display();
                }
            }

            if (swap == false)
            {
                break;
            }
        }

        // end the current frame
        
    }

    return 0;
}