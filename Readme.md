  # Sorting Visualizer

This project is a simple sorting algorithm visualizer built in C Language and using SDL2 and SDL2_ttf Library . 
It demonstrates the Bubble Sort and Selection Sort algorithms through graphical visualization .A sorting visualizer is a graphical application that visually demonstrates how various sorting algorithms work. These visualizations help in understanding the internal processes of sorting algorithms, such as comparisons, swaps, and the overall flow of data, by representing them through visual elements like boxes filled with colors.


## Installation

### Prerequisites

Ensure you have the following installed on your system:

- **C Compiler:** GCC or any C compiler that supports C99 standard.
- **SDL2:** Simple DirectMedia Layer library.
- **SDL2_ttf:** SDL2 extension for TrueType fonts.

### Install Dependencies

Open your terminal and run the following commands to install SDL2 and SDL2_ttf:

### Step 1: Clone the Repository

```
https://github.com/UtsavSingh29/Sorting_Visualizer_C_Project.git
cd sorting-visualizer
```
### Step 2: Ubuntu/Debian
```
sudo apt-get update
sudo apt-get install libsdl2-dev libsdl2-ttf-dev
```
### Step 3: Mac Os
```
brew install sdl2 sdl2_ttf
```
## Windows
Download the development libraries for SDL2 and SDL2_ttf from the SDL website.
Extract the contents and set up the environment variables or include directories in your compiler.
```
https://www.youtube.com/watch?v=H08t6gD1Y1E&t=13s
```

Build
Using GCC
To build the project, navigate to the project directory in your terminal 

## Execute Command
```
gcc -o Sorting_Visualizer Sorting_Visulaizer.c -lSDL2 -lSDL2_ttf
```
Once the build is complete, you can run the program by executing:
## Run
```
./SortingVisualizer
```
### Usage
Bubble Sort: Click the "Bubble Sort" button to visualize the Bubble Sort algorithm.
Selection Sort: Click the "Selection Sort" button to visualize the Selection Sort algorithm.
Reset: Click the "Reset" button to generate a new random array and reset the visualization.

## Features

### Visual Representation:

#### Bars/Boxes: 
The elements of the array being sorted are typically represented as bars or boxes of varying heights (or colors), where each height corresponds to the value of the element.
#### Color Coding:
Colors are used to indicate different states of elements during sorting—such as elements currently being compared, swapped, or already sorted.
#### Algorithm Selection:
The visualizer allows users to choose different sorting algorithms (e.g., Bubble Sort, Selection Sort) and observe how each algorithm sorts the same array differently.
#### Step-by-Step Execution:
The sorting process is often broken down into steps, allowing users to see each individual comparison, swap, or decision made by the algorithm. This can be done either manually (by clicking a "Next" button) or automatically (with a delay between steps).
#### Reset Buttons: 
Users can start or stop the sorting process, or reset the array to its original state.

## Color Legend

A color legend is typically included to explain what each color represents in the context of the sorting process, helping users to understand the meaning of the visual cues.
Blue: Currently selected index.
Pink: Element currently being compared.
Yellow: Current minimum element in Selection Sort.
Green: Correctly sorted element.
Red: Unsorted elements.

#### Educational Value:

Sorting visualizers are excellent educational tools, especially for students learning about sorting algorithms. By watching the algorithms in action, users can develop a more intuitive understanding of how each algorithm works, its efficiency, and its complexity.


### Usage
Click on the Bubble Sort button to start the Bubble Sort visualization.
Click on the Selection Sort button to start the Selection Sort visualization.
Click on the Reset button to reset the array and restart the process.

### Contributing
Feel free to fork this repository, make changes, and submit pull requests. Any contributions that improve the project are welcome!

