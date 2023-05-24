#include "settings.h"
#include "barsDisplay.h"
#include "sortingAlgorithms.h"

const int BAR_AREA_HEIGHT = 200;
const int NUM_BARS = BAR_AREA_HEIGHT;
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = BAR_AREA_HEIGHT + 100;
const int BAR_WIDTH = SCREEN_WIDTH / NUM_BARS;
const int SLEEP_TIME = 5;

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
    sf::IntRect buttonSelectionSort(300, BAR_AREA_HEIGHT, 100, 100);
    sf::IntRect buttonInsertionSort(400, BAR_AREA_HEIGHT, 100, 100);

    sf::RectangleShape button(sf::Vector2f(100, 100));

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
                    std::cout << "Randomizing" << std::endl;
                    myBarsDisplay.randomiseBars();
                    //myBarsDisplay.sortArray();
                }
                //BubbleSort
                if (buttonBubbleSort.contains(mousePos))
                {
                    std::cout << "Bubble Sorting" << std::endl;
                    bubbleSort(window, myBarsDisplay);
                }
                //QuickSort
                if (buttonQuickSort.contains(mousePos))
                {
                    std::cout << "Quick Sorting" << std::endl;
                    quickSort(window, 0, NUM_BARS - 1, myBarsDisplay);
                    myBarsDisplay.clearBarArea(window);
                }
                //SelectionSort
                if (buttonSelectionSort.contains(mousePos))
                {
                    std::cout << "Selection Sorting" << std::endl;
                    selectionSort(window, myBarsDisplay);
                    myBarsDisplay.clearBarArea(window);
                }
                //InsertionSort
                if (buttonInsertionSort.contains(mousePos))
                {
                    std::cout << "Selection Sorting" << std::endl;
                    insertionSort(window, myBarsDisplay);
                    myBarsDisplay.clearBarArea(window);
                }
            }
        }

        window.clear(sf::Color::Black);

        //Display objects on screen

        button.setPosition(0, BAR_AREA_HEIGHT);
        button.setFillColor(sf::Color::Magenta);
        window.draw(button);

        button.setPosition(100, BAR_AREA_HEIGHT);
        button.setFillColor(sf::Color::Red);
        window.draw(button);

        button.setPosition(200, BAR_AREA_HEIGHT);
        button.setFillColor(sf::Color::Blue);
        window.draw(button);

        button.setPosition(300, BAR_AREA_HEIGHT);
        button.setFillColor(sf::Color::Yellow);
        window.draw(button);

        button.setPosition(400, BAR_AREA_HEIGHT);
        button.setFillColor(sf::Color::Cyan);
        window.draw(button);


        if (!myBarsDisplay.checkIfSorted()) {
            myBarsDisplay.clearBarArea(window);
            myBarsDisplay.drawBarArray(window);
        }
        else {
            myBarsDisplay.clearBarArea(window);
            myBarsDisplay.drawBarArray(window, sf::Color::Green);
        }

        window.display();

        //Display current state to the user
        //window.display();
    }

    return 0;
}