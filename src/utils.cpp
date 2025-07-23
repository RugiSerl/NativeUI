#include "utils.hpp"

template<class T> std::vector<T> rotateVector(std::vector<T> vector, unsigned int offset) {
    std::vector<T> newVector(vector.size());
    int i = 0;
    for (T element: vector) {
        newVector.at(i) = vector.at((i+offset)%vector.size());
        i++;
    }
    return newVector;
}