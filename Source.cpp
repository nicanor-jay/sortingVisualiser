#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <random>
#include <iostream>
#include <stdlib.h> 

const int screenWidth = 1000;
const int screenHeight = 500;
const int barAreaHeight = 400;

const int numBars = 200;
const int barWidth = screenWidth / numBars;

sf::RectangleShape rect;

int barArray[numBars] = {};

void populateBarArray() {
    // Populate array list for bar heights
    for (int i = 0; i < numBars; i++) {
        barArray[i] = (rand() % barAreaHeight) + 1;
        std::cout << barArray[i] << '\n';
    }
}

void displayBarArray(sf::RenderWindow &window) {
    window.clear(sf::Color::Black);
    for (int k = 0; k < numBars; k++)
    {
        rect.setSize(sf::Vector2f(barWidth, barArray[k]));
        rect.setFillColor(sf::Color::White);
        rect.setPosition(k * barWidth, barAreaHeight - barArray[k]);
        window.draw(rect);
    }

    window.display();
}

void bubbleSort(sf::RenderWindow& window) {
    bool sorted = false;
    bool swap = false;
    int temp;

    // Bubblesort Code
    if (sorted ==false) {
        for (int i = 0; i < (numBars - 1); i++)
        {
            swap = false;

            for (int j = 0; j < numBars - i - 1; j++)
            {
                if ((barArray[j] > barArray[j + 1] )&& (sorted == false))
                {
                    std::cout << "Swapping index " << j << " & " << j + 1 << '\n';
                    //Swap
                    temp = barArray[j];
                    barArray[j] = barArray[j + 1];
                    barArray[j + 1] = temp;

                    displayBarArray(window);

                    swap = true;
                }
            }

            if (swap == false)
            {
                sorted = truegit;
                    
            }
        }
    }
    else {
        std::cout << "Sorted\n";
    }
}

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Sorting Visualiser");

    int temp;
    bool swap = false;
    //bool sorted = false;
    sf::Vector2i mousePos;
    sf::IntRect buttonBubbleSort(0, barAreaHeight, 100, 100);
    sf::IntRect buttonRandomise(100, barAreaHeight, 100, 100);

    sf::RectangleShape button(sf::Vector2f(100, 100));

    populateBarArray();

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            // "close requested" event: we close the window
                case sf::Event::Closed:
                    window.close();
                case sf::Event::MouseButtonPressed:
                    mousePos = sf::Mouse::getPosition(window);
                    std::cout << mousePos.x << " " << mousePos.y << '\n';
                   
                    //Randomise bars
                    if (buttonRandomise.contains(mousePos)) 
                    {
                        populateBarArray();
                    }

                    //BubbleSort
                    if (buttonBubbleSort.contains(mousePos)) 
                    {
                        std::cout << "BUTTON PRESSED!!!!!!!!\n";
                        bubbleSort(window);
                    }
            }
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        //button.setPosition(0, barAreaHeight);
        //button.setFillColor(sf::Color::Green);
        //window.draw(button);

        displayBarArray(window);
    }
    return 0;
}