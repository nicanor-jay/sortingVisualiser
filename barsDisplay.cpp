#include "barsDisplay.h"
#include "settings.h"

extern const int NUM_BARS;
sf::RectangleShape rect;

barsDisplay::barsDisplay() {
    for (int i = 0; i < NUM_BARS; i++) {
        this->barArray.push_back((rand() % BAR_AREA_HEIGHT) + 1);
        //barArray[i] = (rand() % BAR_AREA_HEIGHT) + 1;
        std::cout << barArray[i] << '\n';
    }
};

void barsDisplay::randomiseBars() {
    for (int i = 0; i < NUM_BARS; i++) {
        barArray[i] = (rand() % BAR_AREA_HEIGHT) + 1;
        std::cout << barArray[i] << '\n';
    }
}

void barsDisplay::drawBar(int index, sf::Color color) {
    rect.setFillColor(color);
    rect.setSize(sf::Vector2f(BAR_WIDTH, barArray[index]));
    rect.setPosition(index * BAR_WIDTH, BAR_AREA_HEIGHT - barArray[index]);
}

void barsDisplay::drawBarArray(sf::RenderWindow& window) {
    window.clear(sf::Color::Black);
    for (int i = 0; i < NUM_BARS; i++) {
        drawBar(i);
        window.draw(rect);
    }
}

int barsDisplay::getValueAtIndex(int i) {
    return barArray[i];
}

void barsDisplay::setValueAtIndex(int i, int val) {
    barArray[i] = val;
}

bool barsDisplay::checkIfSorted() {
    for (int i = 0; i < NUM_BARS - 1; i++) {
        if (barArray[i] > barArray[i + 1]) {
            drawBar(i, sf::Color::Red);
            std::cout << "NOT SORTED\n";
            return false;
        }
        drawBar(i, sf::Color::Green);
    }
    std::cout << "SORTED\n";
    return true;
}

void barsDisplay:: verifySorted(sf::RenderWindow& window) {
    std::cout << "SORTED, MAKING GREEN\n";

    for (int i = 0; i < NUM_BARS - 1; i++) {
        drawBar(i, sf::Color::Green);
        window.draw(rect);
    }
    drawBar(NUM_BARS - 1, sf::Color::Green);
    window.draw(rect);
}

void barsDisplay::swapBars(int index1, int index2) {
    int temp = barArray[index1];
    barArray[index1] = barArray[index2];
    barArray[index2] = temp;
}

void barsDisplay::sortArray() {
    std::sort(barArray.begin(), barArray.end());
}