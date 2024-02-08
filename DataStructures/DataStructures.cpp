#include <iostream>
#include <vector>
#include <numeric>

// TODO: implement this function to return a Pascal Triangle
std::vector<std::vector<int>> pascalTriangle(int row) {

    std::vector<std::vector<int>> triangle;

    for (int i = 0; i <= row; i++) {
        triangle.push_back({});
        int a = 1;
        for (int j = 0; j < i+1; j++) {
            if (j == 0) {
                triangle[i].push_back(1);
            }
            else {
                triangle[i].push_back(a);
            }
            a = a * (i - j) / (j + 1);
        }
    }

    return triangle;
}

// TODO: implement this function to print Pascal Triangles 
void printPascalTriangle(const std::vector<std::vector<int>>& triangle) {
    for (int i = 0; i <= 8; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << triangle[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// TODO: implement this function to return comparison result. See main() for usage. 
std::vector<bool> compare(const std::vector<std::vector<int>>& triangle,
    const std::vector<int> allegedSummations) {
    std::vector<bool> equalVec;

    int rowSum = 0;
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