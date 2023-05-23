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

                    bars.drawBarArray(window);
                    window.display();
                    //sf::sleep(sf::milliseconds(1));

                    swap = true;
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
    bars.verifySorted(window);
}