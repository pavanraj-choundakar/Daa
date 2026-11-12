
#include <iostream>
using namespace std;

// Function to find maximum profit
int maxProfit(int a, int b)
{
    return (a > b) ? a : b;
}

// Recursive function for 0-1 Knapsack
int knapSack(int W, int wt[], int val[], int n)
{
    // Base condition
    if (n == 0 || W == 0)
        return 0;

    // If weight of current item is greater than capacity
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);

    // Include the current item
    int include = val[n - 1] +
                  knapSack(W - wt[n - 1], wt, val, n - 1);

    // Exclude the current item
    int exclude = knapSack(W, wt, val, n - 1);

    return maxProfit(include, exclude);
}

// Main function
int main()
{
    int profit[] = {60, 100, 120, 80};
    int weight[] = {10, 20, 30, 15};

    int W = 35;

    int n = sizeof(profit) / sizeof(profit[0]);

    cout << "Maximum Profit: "
         << knapSack(W, weight, profit, n) << endl;

    return 0;
}

output
g++ 0-1knapsack.cpp -o knapsack
.\knapsack.exe



OUTPUT 
anika_halate@pavnu:/mnt/d/DAA$ g++ 0-1knapsack.cpp -o knapsack 
anika_halate@pavnu:/mnt/d/DAA$ ./knapsack 
Maximum Profit: 180
