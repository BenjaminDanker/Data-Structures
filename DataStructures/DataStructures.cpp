#include <iostream>
#include <vector>
#include <numeric>


std::vector<std::vector<int>> pascalTriangle(int row) {

    std::vector<std::vector<int>> triangle;

    // row iteration
    for (int i = 0; i <= row; i++) {
        triangle.push_back({});
        int a = 1;
        // column iteration
        for (int j = 0; j < i+1; j++) {
            // start of triangle
            if (j == 0) {
                triangle[i].push_back(1);
            }
            else {
                triangle[i].push_back(a);
            }
            // number in triangle is equal to the sum of the two numbers above it
            a = a * (i - j) / (j + 1);
        }
    }

    return triangle;
}

void printPascalTriangle(const std::vector<std::vector<int>>& triangle) {
    for (int i = 0; i <= 8; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << triangle[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<bool> compare(const std::vector<std::vector<int>>& triangle,
    const std::vector<int> allegedSummations) {
    std::vector<bool> equalVec;

    int rowSum = 0;
    // row iteration
    for (int i = 0; i <= allegedSummations.size()-1; i++) {
        rowSum = std::accumulate(triangle[i].begin(), triangle[i].end(), 0);
        
        if (rowSum == allegedSummations[i]) {
            equalVec.push_back(true);
        }
        else {
            equalVec.push_back(false);
        }
    }

    return equalVec;
}


int main()
{
    // part 1: generate and print Pascal Triangle
    int rows = 8;
    auto triangle = pascalTriangle(rows);
    printPascalTriangle(triangle);
    std::cout << std::endl;

    // part 2: check alleged summations
    // expected returrn: {1, 1, 0, 1, 0, 1, 0, 1, 1, 0}
    std::vector<int> allegedSum{ 1, 2, 5, 8, 17, 32, 65, 128, 256, 511 };
    auto sumCheck = compare(pascalTriangle(allegedSum.size()), allegedSum);
    for (auto b : sumCheck) {
        std::cout << b << " ";
    }

    std::cout << std::endl;

}