/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ShellSort.h
 * Author: LTSACH
 *
 * Created on 23 August 2020, 16:45
 */

#ifndef SHELLSORT_H
#define SHELLSORT_H
#include "sorting/ISort.h"

template<class T>
class ShellSort: public ISort<T>{
private:
    int *num_segment_list;
    int num_phases;
    
public:
    ShellSort(int *num_segment, int num_phases){
        this->num_phases = num_phases;
        this->num_segment_list = new int[num_phases];
        for(int idx=0; idx < num_phases; idx++) 
            this->num_segment_list[idx] = num_segment[idx];
    }
    ~ShellSort(){
        delete []num_segment_list;
    }
    
    
    void sortSegment(T array[], int size, 
            int segment_idx, int cur_segment_total,
            int (*comparator)(T&, T&)){
        //YOUR CODE HERE
        int curr;
        int j;
        T temp;
        curr = segment_idx + cur_segment_total;
        while (curr < size){
            temp = array[curr];
            j = curr - cur_segment_total;
            while ((j >= 0) && (comparator(temp, array[j]) <0)){
                array[j + cur_segment_total] = array[j];
                j -= cur_segment_total;
            }
            array[j + cur_segment_total] = temp;
            curr += cur_segment_total;
        }
    }
    /*
    shell_sort
    -----------
    num_segments: 
         + The first must be 1, for examples: [1,3,7]
    */
    void sort(T array[], int size, int (*comparator)(T&,T&)){
        //YOUR CODE HERE
        for (int k = this->num_phases -1; k >=0; k--){
            int nsegment = num_segment_list[k];
            for (int segment_idx = 0; segment_idx < nsegment; segment_idx++){
                sortSegment(array, size, segment_idx, nsegment, comparator);
            }
        }
    }
};

#endif /* SHELLSORT_H */

