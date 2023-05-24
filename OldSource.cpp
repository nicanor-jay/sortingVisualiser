//#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>
//#include <random>
//#include <iostream>
//#include <stdlib.h> 
//
//const int screenWidth = 1000;
//const int screenHeight = 500;
//const int barAreaHeight = 400;
//
//const int numBars = 100;
//const int barWidth = screenWidth / numBars;
//
//sf::RectangleShape rect;
//
//int barArray[numBars] = {};
//
//void populateBarArray() {
//    // Populate array list for bar heights
//    std::cout << "New bar array\n";
//    for (int i = 0; i < numBars; i++) {
//        barArray[i] = (rand() % barAreaHeight) + 1;
//        std::cout << barArray[i] << '\n';
//    }
//}
//
//void clearBarArea(sf::RenderWindow& window) {
//    rect.setFillColor(sf::Color::Black);
//    rect.setSize(sf::Vector2f(screenWidth, barAreaHeight));
//    rect.setPosition(0, 0);
//    window.draw(rect);
//}
//
//void drawBarArray(sf::RenderWindow& window) {
//    for (int k = 0; k < numBars; k++)
//    {
//        rect.setSize(sf::Vector2f(barWidth, barArray[k]));
//        rect.setFillColor(sf::Color::White);
//        rect.setPosition(k * barWidth, barAreaHeight - barArray[k]);
//        window.draw(rect);
//    }
//}
//
//// BUBBLESORT
//
//void bubbleSort(sf::RenderWindow& window) {
//    bool sorted = false;
//    bool swap = false;
//    int temp;
//
//    // Bubblesort Code
//    if (sorted ==false) {
//        for (int i = 0; i < (numBars - 1); i++)
//        {
//            swap = false;
//
//            for (int j = 0; j < numBars - i - 1; j++)
//            {
//                if ((barArray[j] > barArray[j + 1] )&& (sorted == false))
//                {
//                    std::cout << "Swapping index " << j << " & " << j + 1 << '\n';
//                    //Swap
//                    temp = barArray[j];
//                    barArray[j] = barArray[j + 1];
//                    barArray[j + 1] = temp;
//
//                    clearBarArea(window);
//                    drawBarArray(window);
//                    window.display();
//
//                    swap = true;
//                }
//            }
//
//            if (swap == false)
//            {
//                sorted = true;
//            }
//        }
//    }
//    else {
//        std::cout << "Sorted\n";
//    }
//}
//
//// QUICK SORT
//
//void swapIndexes(int index1, int index2) {
//    int temp;
//
//    std::cout << "Swapping indexes " << index1 << " & " << index2 << '\n';
//
//    temp = barArray[index1];
//    barArray[index1] = barArray[index2];
//    barArray[index2] = temp;
//}
//
//int partition( int start, int end)
//{
//    int pivot = barArray[start];
//
//    int count = 0;
//    for (int i = start + 1; i <= end; i++) {
//        if (barArray[i] <= pivot)
//            count++;
//    }
//
//    // Giving pivot element its correct position
//    int pivotIndex = start + count;
//    swapIndexes(pivotIndex, start);
//
//    // Sorting left and right parts of the pivot element
//    int i = start, j = end;
//
//    while (i < pivotIndex && j > pivotIndex) {
//
//        while (barArray[i] <= pivot) {
//            i++;
//        }
//
//        while (barArray[j] > pivot) {
//            j--;
//        }
//
//        if (i < pivotIndex && j > pivotIndex) {
//            swapIndexes(i++, j--);
//        }
//    }
//
//    return pivotIndex;
//}
//
//void quickSort(sf::RenderWindow& window, int start, int end)
//{
//
//    // base case
//    if (start >= end)
//        return;
//
//    // partitioning the array
//    int p = partition(start, end);
//
//    sf::RectangleShape rect(sf::Vector2f(barWidth, barArray[p]));
//    rect.setPosition(p * barWidth, barAreaHeight - barArray[p]);
//    rect.setFillColor(sf::Color::Blue);
//
//    drawBarArray(window);
//    window.draw(rect);
//    window.display();
//    sf::sleep(sf::milliseconds(200));
//    clearBarArea(window);
//
//    // Sorting the left part
//    quickSort(window, start, p - 1);
//
//    // Sorting the right part
//    quickSort(window, p + 1, end);
//    //drawBarArray(window);
//    //rect.setFillColor(sf::Color::Red);
//    //window.draw(rect);
//    //window.display();
//    //sf::sleep(sf::milliseconds(100));
//    //clearBarArea(window);
//
//}
//
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