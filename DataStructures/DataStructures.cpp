#include <iostream>
#include <vector>
#include <algorithm>

bool isSet(std::vector<int>& vec) {
    for (int i = 0; i < vec.size() - 1; i++) {
        for (int j = i + 1; j < vec.size(); j++) {
            if (vec[i] == vec[j]) {
                return false;
            }
        }
    }

    return true;
}

std::vector<int> setUnion(std::vector<int>& vec1, std::vector<int>& vec2) {
    std::vector<int> unifiedVec = vec1;
    
    std::vector<int>::iterator it;
    for (auto i : vec2) {
        it = find(vec1.begin(), vec1.end(), i);
        if (it == vec1.end()) {
            unifiedVec.push_back(i);
        }
    }

    return unifiedVec;
}

std::vector<int> setIntersecting(std::vector<int>& vec1, std::vector<int>& vec2) {
    std::vector<int> intersectingVec;

    for (auto i : vec1) {
        for (auto j : vec2) {
            if (i == j) {
                intersectingVec.push_back(i);
            }
        }
    }

    return intersectingVec;
}

std::vector<int> setDifference(std::vector<int>& vec1, std::vector<int>& vec2) {
    std::vector<int> differenceVec;

    std::vector<int>::iterator it;
    for (auto i : vec1) {
        it = find(vec2.begin(), vec2.end(), i);
        if (it == vec2.end()) {
            differenceVec.push_back(i);
        }
    }

    return differenceVec;
}

int main()
{
    // is set
    std::vector<int> vec1 = { 1,4,5,6,1 };
    bool isSetBool = isSet(vec1);

    std::cout << "isSet " << isSetBool << std::endl;


    // union
    std::vector<int> vec2 = { 1,2,3,4 };
    std::vector<int> vec3 = { 2,4,5,6 };
    std::vector<int> unifiedVec = setUnion(vec2, vec3);

    std::cout << "unified ";
    for (auto x : unifiedVec) {
        std::cout << x << ", ";
    }
    std::cout << std::endl;


    // intersection
    std::vector<int> intersectingVec = setIntersecting(vec2, vec3);

    std::cout << "intersecting ";
    for (auto x : intersectingVec) {
        std::cout << x << ", ";
    }
    std::cout << std::endl;


    // difference
    std::vector<int> differenceVec = setDifference(vec3, vec2);

    std::cout << "difference ";
    for (auto x : differenceVec) {
        std::cout << x << ", ";
    }
    std::cout << std::endl;
}