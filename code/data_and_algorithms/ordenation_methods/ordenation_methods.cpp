#include "ordenation_methods.h"

void bsort(float vt[], int size) {
    float aux;

    for(unsigned int i = 0; i < size; ++i) {
        for(unsigned int j = 0; j < size; ++j) {
            if(vt[i] < vt[j]) {
                aux = vt[i];
                vt[i] = vt[j];
                vt[j] = aux;
            }
        }
    }
}