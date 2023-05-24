#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <random>
#include <iostream>
#include <stdlib.h> 
#include <vector>
#include <algorithm>
#include "barsDisplay.h"

void bubbleSort(sf::RenderWindow& window, barsDisplay& bars);

int partition(int start, int end, barsDisplay& bars);
void quickSort(sf::RenderWindow& window, int start, int end, barsDisplay& bars);

void selectionSort(sf::RenderWindow& window, barsDisplay& bars);

void insertionSort(sf::RenderWindow& window, barsDisplay& bars);