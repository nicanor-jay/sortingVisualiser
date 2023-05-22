#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <random>
#include <iostream>
#include <stdlib.h> 
#include <vector>

const int screenWidth = 1000;
const int screenHeight = 500;
const int barAreaHeight = 400;

const int numBars = 100;
const int barWidth = screenWidth / numBars;

sf::RectangleShape rect;

class barsDisplay {
private:
    int barArray[numBars];
public:
    //Default constructor
    barsDisplay() {
        for (int i = 0; i < numBars; i++) {
            barArray[i] = (rand() % barAreaHeight) + 1;
            std::cout << barArray[i] << '\n';
        }
    };

    void randomiseBars() {
        for (int i = 0; i < numBars; i++) {
            barArray[i] = (rand() % barAreaHeight) + 1;
            std::cout << barArray[i] << '\n';
        }
    }

    void drawBar(int index) {
        rect.setSize(sf::Vector2f(barWidth, barArray[index]));
        rect.setFillColor(sf::Color::White);
        rect.setPosition(index * barWidth, barAreaHeight - barArray[index]);
    }

    void printBarInfo(int index) {
        for (int i : barArray) {
            std::cout << i;
        }
    }

    void swapBars(int index1, int index2) {
        int temp = barArray[index1];
        barArray[index1] = barArray[index2];
        barArray[index2] = temp;
    }
};

class buttonsDisplay {
private:
public:
    buttonsDisplay() {
};
};


int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Sorting Visualiser");

    barsDisplay temp;
    sf::Vector2i mousePos;

    //Determine Button sizes
    sf::IntRect buttonRandomise(0, barAreaHeight, 100, 100);
    sf::IntRect buttonBubbleSort(100, barAreaHeight, 100, 100);
    sf::IntRect buttonQuickSort(200, barAreaHeight, 100, 100);

    window.clear(sf::Color::Black);
    while (window.isOpen()) {
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
                   
                    //Randomise bars
                    if (buttonRandomise.contains(mousePos)) 
                    {
                        //temp.randomiseBars();

                        temp.swapBars(10, 40);
                    }


            }
        }


        window.clear(sf::Color::Black);

        for (int i = 0; i < numBars; i++) {
            temp.drawBar(i);
            window.draw(rect);
        }

        //Display current state to the user
        window.display();
    }

    return 0;
}

//int main()
//{
//    // create the window
//    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Sorting Visualiser");
//
//    int temp;
//    bool swap = false;
//    //bool sorted = false;
//    sf::Vector2i mousePos;
//    sf::IntRect buttonRandomise(0, barAreaHeight, 100, 100);
//    sf::IntRect buttonBubbleSort(100, barAreaHeight, 100, 100);
//    sf::IntRect buttonQuickSort(200, barAreaHeight, 100, 100);
//
//    sf::RectangleShape button(sf::Vector2f(100, 100));
//
//    populateBarArray();
//
//    // run the program as long as the window is open
//    while (window.isOpen())
//    {
//        // check all the window's events that were triggered since the last iteration of the loop
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            switch (event.type)
//            {
//            // "close requested" event: we close the window
//                case sf::Event::Closed:
//                    window.close();
//                case sf::Event::MouseButtonPressed:
//                    mousePos = sf::Mouse::getPosition(window);
//                   
//                    //Randomise bars
//                    if (buttonRandomise.contains(mousePos)) 
//                    {
//                        populateBarArray();
//                    }
//
//                    //BubbleSort
//                    if (buttonBubbleSort.contains(mousePos)) 
//                    {
//                        bubbleSort(window);
//
//                    }
//
//                    //QuickSort
//                    if (buttonQuickSort.contains(mousePos))
//                    {
//                        quickSort(window, 0, numBars - 1);
//                    }
//
//            }
//        }
//
//        // clear the window with black color
//        window.clear(sf::Color::Black);
//
//        //Display objects on screen
//        button.setPosition(0, barAreaHeight);
//        button.setFillColor(sf::Color::Magenta);
//        window.draw(button);
//
//        button.setPosition(100, barAreaHeight);
//        button.setFillColor(sf::Color::Green);
//        window.draw(button);
//
//
//        button.setPosition(200, barAreaHeight);
//        button.setFillColor(sf::Color::Blue);
//        window.draw(button);
//
//        drawBarArray(window);
//
//        // Display current frame
//        window.display();
//    }
//    return 0;
//}