#include <iostream>
#include <vector>
#include <random>

int main()
{
    // Setting up the dimensions for matrices A and B

    int m = 4;
    int n = 4;
    int p = 4;

    // Spinning up a random number generator

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(1.0, 2.0);

    // Setting up the multiplication loop...

    for (int iter = 0; iter < 1000000; ++iter)
    {
        // Create the matrices to hold the random values

        std::vector<std::vector<float>> A(m, std::vector<float>(n));
        std::vector<std::vector<float>> B(n, std::vector<float>(p));

        // Populate the matrices with the random values

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                A[i][j] = dis(gen);
            }
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < p; ++j)
            {
                B[i][j] = dis(gen);
            }
        }

        std::cout << "Current value of Matrix A: " << "\n";

        for (const auto& row : A)
        {
            for (float val : row)
            {
                std::cout << val << " "; 
            }
            std::cout << "\n";
        }

        std::cout << "\nCurrent value of Matrix B: " << "\n";

        for (const auto& row : B)
        {
            for (float val : row)
            {
                std::cout << val << " ";
            }
            std::cout << "\n";
        }

        // Matrix C with dimensions m x p initialized to 0

        std::vector<std::vector<float>> C(m, std::vector<float>(p, 0.0));

        // Matrix multiplication using Einstein Summation Convention logic

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < p; ++j)
            {
                for (int k = 0; k < n; ++k)
                {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        std::cout << "\nCurrent result of Matrix C: " << "\n";

        for (const auto& row : C)
        {
            for (float val : row)
            {
                std::cout << val << " ";
            }
            std::cout << "\n"; 
        }

        std::cout << "\nIteration " << iter + 1 << " complete.\n";
    }

    std::cout << "\nMatrix multiplication performed 1 million times.\n";
    return 0;
}
