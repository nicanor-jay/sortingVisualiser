#include "settings.h"
#include "barsDisplay.h"
#include "sortingAlgorithms.h"

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 500;
const int BAR_AREA_HEIGHT = 400;
const int NUM_BARS = 100;
const int BAR_WIDTH = SCREEN_WIDTH / NUM_BARS;

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Sorting Visualiser");

    barsDisplay myBarsDisplay;

    sf::Vector2i mousePos;

    //Determine Button sizes
    sf::IntRect buttonRandomise(0, BAR_AREA_HEIGHT, 100, 100);
    sf::IntRect buttonBubbleSort(100, BAR_AREA_HEIGHT, 100, 100);
    sf::IntRect buttonQuickSort(200, BAR_AREA_HEIGHT, 100, 100);

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
                    myBarsDisplay.randomiseBars();
                    //myBarsDisplay.sortArray();
                }
                //BubbleSort
                if (buttonBubbleSort.contains(mousePos))
                {
                    bubbleSort(window, myBarsDisplay);
                }
            }
        }

        window.clear(sf::Color::Black);

        //std::cout << myBarsDisplay.getValueAtIndex(0);

        if (!myBarsDisplay.checkIfSorted()) {
            myBarsDisplay.drawBarArray(window);
        }
        else {
            myBarsDisplay.verifySorted(window);
        }

        //Display current state to the user
        window.display();
    }

    return 0;
}

//int main()
//{
//    // create the window
//    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Sorting Visualiser");
//
//    int temp;
//    bool swap = false;
//    //bool sorted = false;
//    sf::Vector2i mousePos;
//    sf::IntRect buttonRandomise(0, BAR_AREA_HEIGHT, 100, 100);
//    sf::IntRect buttonBubbleSort(100, BAR_AREA_HEIGHT, 100, 100);
//    sf::IntRect buttonQuickSort(200, BAR_AREA_HEIGHT, 100, 100);
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
//                        quickSort(window, 0, NUM_BARS - 1);
//                    }
//
//            }
//        }
//
//        // clear the window with black color
//        window.clear(sf::Color::Black);
//
//        //Display objects on screen
//        button.setPosition(0, BAR_AREA_HEIGHT);
//        button.setFillColor(sf::Color::Magenta);
//        window.draw(button);
//
//        button.setPosition(100, BAR_AREA_HEIGHT);
//        button.setFillColor(sf::Color::Green);
//        window.draw(button);
//
//
//        button.setPosition(200, BAR_AREA_HEIGHT);
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