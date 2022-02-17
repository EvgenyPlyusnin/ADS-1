// Copyright 2022 NNTU-CS
#include <cstdint>
#include <iostream>
#include <cmath>
#include <vector>
#include "alg.h"


bool checkPrime(uint64_t value) {
    if (value == 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(value); i++) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    int *mass = new int[1000000];
    for (int i = 1; i < 1000000; i++) {
        mass[i] = i;
        if (i == 1) {
            mass[i] = 0;
        }
    }
    int i = 1;
    while (i <= 1000000) {
        if (mass[i] != 0) {
            int j = i * 2;
            while (j <= 1000000) {
                mass[j] = 0;
                j += i;
            }
        }
        i++;
    }
    std::vector <int> vect;
    for (int i = 0; i < 1000000; i++) {
        if (mass[i] != 0) {
            vect.push_back(mass[i]);
        }
    }
    return vect[n-1];
}

uint64_t nextPrime(uint64_t value) {
    value++;
    while (true) {
        if (checkPrime(value) == true) {
            return value;
        }
        value++;
    }
}

uint64_t sumPrime(uint64_t hbound) {
    int *mass = new int[hbound];
    for (int i = 1; i < hbound; i++) {
        mass[i] = i;
        if (i == 1) {
            mass[i] = 0;
        }
    }
    int i = 1;
    while (i <= hbound) {
        if (mass[i] != 0) {
            int j = i * 2;
            while (j <= hbound) {
                mass[j] = 0;
                j += i;
            }
        }
        i++;
    }
    int sum = 0;
    for (int i = 0; i < hbound; i++) {
        if (mass[i] != 0) {
            sum += mass[i];
        }
    }
    return sum;
}
