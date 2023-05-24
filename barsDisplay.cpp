#include "barsDisplay.h"
#include "settings.h"

extern const int NUM_BARS;
sf::RectangleShape rect;

barsDisplay::barsDisplay() {
    for (int i = 0; i < NUM_BARS; i++) {
        this->barArray.push_back(BAR_AREA_HEIGHT / NUM_BARS * i);
        //barArray[i] = (rand() % BAR_AREA_HEIGHT) + 1;
        std::cout << barArray[i] << '\n';
    }
    randomiseBars();
};

void barsDisplay::randomiseBars() {
    std::random_shuffle(barArray.begin(), barArray.end());
}

void barsDisplay::drawBar(int index, sf::RenderWindow& window, sf::Color color) {
    rect.setFillColor(color);
    rect.setSize(sf::Vector2f(BAR_WIDTH, barArray[index]));
    rect.setPosition(index * BAR_WIDTH, BAR_AREA_HEIGHT - barArray[index]);
    window.draw(rect);
}

void barsDisplay::drawBarArray(sf::RenderWindow& window, sf::Color color) {
    for (int i = 0; i < NUM_BARS; i++) {
        drawBar(i, window, color);
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
            return false;
        }
    }
    return true;
}

void barsDisplay:: verifySorted(sf::RenderWindow& window) {
    for (int i = 0; i < NUM_BARS - 1; i++) {
        drawBar(i, window, sf::Color::Green);
        window.display();
        sf::sleep(sf::milliseconds(SLEEP_TIME));
    }
    drawBar(NUM_BARS - 1, window, sf::Color::Green);
}

void barsDisplay::swapBars(int index1, int index2) {
    int temp = barArray[index1];
    barArray[index1] = barArray[index2];
    barArray[index2] = temp;
}

void barsDisplay::sortArray() {
    std::sort(barArray.begin(), barArray.end());
}

void barsDisplay::clearBarArea(sf::RenderWindow& window) {
    rect.setFillColor(sf::Color::Black);
    rect.setSize(sf::Vector2f(SCREEN_WIDTH, BAR_AREA_HEIGHT));
    rect.setPosition(0, 0);
    window.draw(rect);
}