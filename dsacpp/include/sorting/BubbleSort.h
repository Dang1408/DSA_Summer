/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BubbleSort.h
 * Author: LTSACH
 *
 * Created on 23 August 2020, 17:16
 */

#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "sorting/ISort.h"

template<class T>
class BubbleSort: public ISort<T>{
public:
    void sort(T array[], int size, int (*comparator)(T&,T&)){
        //YOUR CODE HERE
        int curr = 0;
        bool flag = false;
        int walker;
        T temp;
        while ((curr < size) && flag == false){
            walker = size -1;
            flag = true;
            while (walker > curr){
                if (comparator(array[walker],array[walker-1]) < 0){
                    flag = false;
                    temp = array[walker];
                    array[walker] = array[walker -1];
                    array[walker -1] = temp;
                }
                walker--;
            }
            curr++;
        }
    }
};


#endif /* BUBBLESORT_H */

