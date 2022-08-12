/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StraightInsertionSort.h
 * Author: LTSACH
 *
 * Created on 23 August 2020, 16:24
 */

#ifndef STRAIGHTINSERTIONSORT_H
#define STRAIGHTINSERTIONSORT_H
#include "sorting/ISort.h"


template<class T>
class StraightInsertionSort: public ISort<T>{
public:
    void sort(T array[], int size, int (*comparator)(T&,T&)){
        //YOUR CODE HERE
        int curr;
        T temp;
        int walker;
        if (size > 1){
            curr = 1;
            while (curr < size){
                temp = array[curr];
                walker = curr -1;
                while ((walker >= 0) && (comparator(temp,array[walker]) < 0)){
                    array[walker +1] = array[walker];
                    walker--;
                }
                array[walker + 1] = temp;
                curr++;
            }
        }
    }
};

#endif /* STRAIGHTINSERTIONSORT_H */

