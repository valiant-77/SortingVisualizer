# Sorting Algorithm Visualizer

A graphical application that visualizes popular sorting algorithms using SDL2. Watch in real-time as algorithms organize data, helping you understand the mechanics of different sorting techniques.

[Download The App](https://www.libsdl.org/download-2.0.php)

## Features

* **Visual Representation**: Watch sorting algorithms in action with animated bar charts
* **Multiple Algorithms**: Includes 5 popular sorting methods
  * Selection Sort
  * Bubble Sort
  * Insertion Sort
  * Merge Sort
  * Quick Sort
* **Customizable Array Size**: Choose array sizes up to 100 elements
* **Color-Coded Elements**: Visual indicators highlight current operations
  * Red bars indicate currently selected elements
  * Green bars show minimum values or partition points
  * White bars represent unsorted elements

## Technologies Used

* C++
* SDL2 (Simple DirectMedia Layer)
* Standard Template Library (STL)

## Installation and Setup

### Prerequisites
* C++ compiler (g++ recommended)
* SDL2 development libraries

### Installing SDL2

#### On Ubuntu/Debian:
```bash
sudo apt-get update
sudo apt-get install libsdl2-dev
```

#### On macOS (using Homebrew):
```bash
brew install sdl2
```

#### On Windows:
Download SDL2 development libraries from [the official SDL website](https://www.libsdl.org/download-2.0.php) and follow the installation instructions.

### Compiling the Program

1. **Clone the repository**
   ```bash
   git clone https://github.com/yourusername/sorting-visualizer.git
   cd sorting-visualizer
   ```

2. **Compile with SDL2**
   ```bash
   g++ -o sorting_visualizer main.cpp -lSDL2
   ```

3. **Run the program**
   ```bash
   ./sorting_visualizer
   ```

## Usage

1. Launch the program
2. Enter the desired array size (maximum 100)
3. Select a sorting algorithm by entering the corresponding number:
   * 0: Selection Sort
   * 1: Bubble Sort
   * 2: Insertion Sort
   * 3: Merge Sort
   * 4: Quick Sort
4. Watch the visualization of your chosen algorithm
5. Close the window when finished

## Sorting Algorithms Explained

### Selection Sort
Repeatedly finds the minimum element from the unsorted portion and places it at the beginning of the unsorted part.

### Bubble Sort
Repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.

### Insertion Sort
Builds the sorted array one item at a time by taking elements from the unsorted part and inserting them into their correct position.

### Merge Sort
A divide-and-conquer algorithm that divides the input array into two halves, recursively sorts them, and merges the sorted halves.

### Quick Sort
Another divide-and-conquer algorithm that picks a "pivot" element and partitions the array around it.



