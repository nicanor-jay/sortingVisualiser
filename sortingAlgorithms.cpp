#include "settings.h"
#include "barsDisplay.h"

//Bubble Sort
void bubbleSort(sf::RenderWindow& window, barsDisplay& bars) {
    bool sorted = bars.checkIfSorted();
    bool swap = false;

    if (bars.checkIfSorted() == false) {
        for (int i = 0; i < (NUM_BARS - 1); i++)
        {
            swap = false;

            for (int j = 0; j < NUM_BARS - i - 1; j++)
            {
                if ((bars.getValueAtIndex(j) > bars.getValueAtIndex(j + 1)) && (sorted == false))
                {
                    std::cout << "Swapping index " << j << " & " << j + 1 << '\n';
                    //Swap
                    bars.swapBars(j, j + 1);

                    bars.clearBarArea(window);
                    bars.drawBarArray(window);
                    window.display();

                    swap = true;
                    sf::sleep(sf::milliseconds(SLEEP_TIME));
                }
            }
            if (swap == false)
            {
                sorted = true;
            }
        }
    }
    else {
        std::cout << "Sorted\n";
    }
}

//Quick Sort
int partition( int start, int end, barsDisplay& bars)
{
    int pivot = bars.getValueAtIndex(start);

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (bars.getValueAtIndex(i) <= pivot)
            count++;
    }

    // Giving pivot element its correct position
    int pivotIndex = start + count;
    bars.swapBars(pivotIndex, start);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (bars.getValueAtIndex(i) <= pivot) {
            i++;
        }

        while (bars.getValueAtIndex(j) > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            bars.swapBars(i++, j--);
        }
    }

    return pivotIndex;
}

void quickSort(sf::RenderWindow& window, int start, int end, barsDisplay& bars)
{

    // base case
    if (start >= end)
        return;

    // partitioning the array
    int p = partition(start, end, bars);

    bars.clearBarArea(window);
    bars.drawBarArray(window);
    bars.drawBar(p, window, sf::Color::Blue);
    window.display();
    sf::sleep(sf::milliseconds(SLEEP_TIME));

    // Sorting the left part
    quickSort(window, start, p - 1, bars);

    // Sorting the right part
    quickSort(window, p + 1, end, bars);
}

// Selection Sort
void selectionSort(sf::RenderWindow& window, barsDisplay& bars) {
    int minIndex;
    for (int i = 0; i < NUM_BARS - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < NUM_BARS; j++) {
            if (bars.getValueAtIndex(j) < bars.getValueAtIndex(minIndex)) {
                minIndex = j;
            }
        }
        bars.swapBars(i, minIndex);
        bars.clearBarArea(window);
        bars.drawBarArray(window);
        window.display();

        sf::sleep(sf::milliseconds(SLEEP_TIME));
    }
}

//Insertion Sort
void insertionSort(sf::RenderWindow& window, barsDisplay& bars) {
    for (int i = 1; i < NUM_BARS; i++) {
        int current = bars.getValueAtIndex(i);
        int j = i - 1;
        while (j >= 0 && bars.getValueAtIndex(j) > current) {
            bars.swapBars(j + 1, j);

            bars.clearBarArea(window);
            bars.drawBarArray(window);
            bars.drawBar(j,window, sf::Color::Blue);
            window.display();
            sf::sleep(sf::milliseconds(SLEEP_TIME));

            j--;
        }
        bars.setValueAtIndex(j + 1, current);
    }
}