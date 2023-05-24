#pragma once
#include <vector>
#include "source.h"

class barsDisplay {
private:
	//int barArray[NUM_BARS];
	std::vector<int> barArray;
public:
	//constructor
	barsDisplay();

	//
	void randomiseBars();

	void drawBar(int index, sf::RenderWindow& window, sf::Color color = sf::Color::White);

	void drawBarArray(sf::RenderWindow& window, sf::Color color = sf::Color::White);

	int getValueAtIndex(int i);

	void setValueAtIndex(int i, int val);

	bool checkIfSorted();

	void verifySorted(sf::RenderWindow& window);

	void swapBars(int index1, int index2);

	void sortArray();

	void clearBarArea(sf::RenderWindow& window);
};