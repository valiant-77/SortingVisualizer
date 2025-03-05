#include <SDL2/SDL.h>
#include <bits/stdc++.h>

using namespace std;

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int max_size=100;
int ARRAY_SIZE; 
const int BAR_GAP = 2;      

void drawArray(SDL_Renderer* renderer, const vector<int>& array, int selectedIndex, int minIndex) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    int barWidth = (WINDOW_WIDTH - (ARRAY_SIZE - 1) * BAR_GAP) / ARRAY_SIZE;  

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        int barHeight = array[i] * (WINDOW_HEIGHT / ARRAY_SIZE);

        if (i == selectedIndex) {
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red for selected index
        } else if (i == minIndex) {
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Green for minimum index
        } else {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White for others
        }

        // Adjust the x position to include the gap
        SDL_Rect rect = {i * (barWidth + BAR_GAP), WINDOW_HEIGHT - barHeight, barWidth, barHeight};
        SDL_RenderFillRect(renderer, &rect);
    }

    SDL_RenderPresent(renderer);
}

void selectionSort(SDL_Renderer* renderer, vector<int>& array) {
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        int minIndex = i;
        // Find the minimum in the unsorted portion of the array
        for (int j = i + 1; j < ARRAY_SIZE; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
            // Always highlight the current scanning position (green), 
            // with the minimum so far highlighted in a different way
            drawArray(renderer, array, j, i);
            SDL_Delay(20); // Delay to visualize the sorting process
        }
        
        // Swap the found minimum with the first unsorted element
        swap(array[i], array[minIndex]);
        drawArray(renderer, array, i, i);
        SDL_Delay(20); // Delay to visualize the swap
    }
}

void bubbleSort(SDL_Renderer* renderer, vector<int>& array) {
    for (int i = ARRAY_SIZE - 1; i >= 0; i--) {
        for (int j = 0; j <= i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
                drawArray(renderer, array, j, i);  // Highlight the end of the unsorted portion
                SDL_Delay(20); // Delay to visualize the swap
            }
            drawArray(renderer, array, j + 1, i);  // Visualize each comparison
            SDL_Delay(20);
        }
    }
}

void insertionSort(SDL_Renderer* renderer, vector<int>& array) {
    for (int i = 1; i < ARRAY_SIZE; ++i) {
        int key = array[i];
        int j = i - 1;

        // Move elements greater than key to one position ahead
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
            drawArray(renderer, array, j + 1, i); // Visualize the shifting
            SDL_Delay(20); // Delay to visualize the process
        }
        array[j + 1] = key;
        drawArray(renderer, array, j + 1, i); // Visualize the final position of key
        SDL_Delay(20); // Delay to visualize the insertion
    }
}

void merge(SDL_Renderer* renderer, vector<int>& array, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = array[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
        drawArray(renderer, array, k, -1); // Visualize the merge process
        SDL_Delay(20); // Delay to visualize the process
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
        drawArray(renderer, array, k, -1); // Visualize the merge process
        SDL_Delay(20); // Delay to visualize the process
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
        drawArray(renderer, array, k, -1); // Visualize the merge process
        SDL_Delay(20); // Delay to visualize the process
    }
}

void mergeSort(SDL_Renderer* renderer, vector<int>& array, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(renderer, array, left, mid);
        mergeSort(renderer, array, mid + 1, right);

        merge(renderer, array, left, mid, right);
    }
}

int partition(SDL_Renderer* renderer, std::vector<int>& arr, int start, int end) {
    int pivot = arr[end];
    int pindex = start;

    for (int i = start; i < end; i++) {
        if (arr[i] < pivot) {
            // Swap elements
            std::swap(arr[i], arr[pindex]);
            
            // Visualize the swap
            drawArray(renderer, arr, i, pindex);
            SDL_Delay(50);  // Delay to make visualization visible
            
            pindex++;
        }
    }

    // Place pivot in its correct position
    std::swap(arr[end], arr[pindex]);
    
    // Visualize final pivot placement
    drawArray(renderer, arr, pindex, end);
    SDL_Delay(50);

    return pindex;
}

void quickSort(SDL_Renderer* renderer, std::vector<int>& arr, int start, int end) {
    if (start < end) {
        // Partition the array
        int p = partition(renderer, arr, start, end);
        
        // Recursively sort left and right subarrays
        quickSort(renderer, arr, start, p - 1);
        quickSort(renderer, arr, p + 1, end);
    }
}

int main(int argc, char* argv[]) {
    // Display instructions in the console
    
    cout << "Sorting Algorithm Visualizer\n";
    cout<<"Enter the size of the array(Max 100): ";
    cin>>ARRAY_SIZE;
    

    if (ARRAY_SIZE > max_size) {
        cout << "Array size exceeds the maximum limit of 100. Setting size to 100.\n";
        ARRAY_SIZE = max_size;
    }
    cout<<endl;
    cout << "Press 0 for Selection Sort\n";
    cout << "Press 1 for Bubble Sort\n";
    cout << "Press 2 for Insertion Sort\n";
    cout << "Press 3 for Merge Sort\n";
    cout << "Press 4 for Quick Sort\n";
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;

    if (choice < 0 || choice > 4) {
        cerr << "Invalid choice! Exiting...\n";
        return 1;
    }

    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Sorting Visualizer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Initialize the array with random values
    vector<int> array(ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        array[i] = rand() % ARRAY_SIZE + 1;
    }

    // Perform the selected sorting algorithm
    switch (choice) {
        case 0:
            selectionSort(renderer, array);
            break;
        case 1:
            bubbleSort(renderer, array);
            break;
        case 2:
            insertionSort(renderer, array);
            break;
        case 3:
            mergeSort(renderer, array, 0, ARRAY_SIZE - 1);
            break;
        case 4:
            quickSort(renderer, array, 0, ARRAY_SIZE - 1);
            break;
    }

    // Draw the final sorted array
    drawArray(renderer, array, -1, -1);

    // Wait for the user to close the window
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
    }

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
