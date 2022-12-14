/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DGraphModel.h
 * Author: LTSACH
 *
 * Created on 23 August 2020, 19:36
 */

#ifndef DGRAPHMODEL_H
#define DGRAPHMODEL_H
#include "graph/AbstractGraph.h"
#include "stacknqueue/Queue.h"
#include "stacknqueue/Stack.h"
#include "hash/XHashMap.h"
#include "stacknqueue/PriorityQueue.h"
#include "sorting/DLinkedListSE.h"


//////////////////////////////////////////////////////////////////////
///////////// GraphModel: Directed Graph Model    ////////////////////
//////////////////////////////////////////////////////////////////////


template<class T>
class DGraphModel: public AbstractGraph<T>{
private:
public:
    DGraphModel(
            bool (*vertexEQ)(T&, T&), 
            string (*vertex2str)(T&) ): 
        AbstractGraph<T>(vertexEQ, vertex2str){
    }
    static DGraphModel<T>* create(T* vertices, int nvertices, Edge<T>* edges, int nedges, bool(*vertexEQ)(T&, T&), string (*vertex2str)(T&)){
        DGraphModel<T>* model = new DGraphModel<T>(vertexEQ, vertex2str);
        for(int vidx = 0; vidx < nvertices; vidx++){
            model->add(vertices[vidx]);
        }
            
        for(int eidx = 0; eidx < nedges; eidx++){
            model->connect(edges[eidx].from, edges[eidx].to, edges[eidx].weight);
        }
            
        return model;
    }
    void connect(T from, T to, float weight=0){
        //YOUR CODE HERE
        typename AbstractGraph<T>::VertexNode* nodeF = this ->getVertexNode(from);
        typename AbstractGraph<T>::VertexNode* nodeT = this -> getVertexNode(to);
        if (nodeF == 0) throw VertexNotFoundException(this -> vertex2Str(*nodeF));
        if (nodeT == 0) throw VertexNotFoundException(this -> vertex2Str(*nodeT));

        nodeF -> connect(nodeT,weight);
    }
    void disconnect(T from, T to){
        //YOUR CODE HERE
        typename AbstractGraph<T>::VertexNode* nodeF = this ->getVertexNode(from);
        typename AbstractGraph<T>::VertexNode* nodeT = this -> getVertexNode(to);
        if (nodeF == 0) throw VertexNotFoundException(this -> vertex2Str(*nodeF));
        if (nodeT == 0) throw VertexNotFoundException(this -> vertex2Str(*nodeT));

        typename AbstractGraph<T>::Edge* edge = nodeF -> getEdge(nodeT);

        if (edge == 0) throw EdgeNotFoundException(this -> edge2Str(*edge));

        nodeF -> removeTo(nodeT);
    }
    void remove(T vertex){
        //YOUR CODE HERE
        typename AbstractGraph<T>::VertexNode* nodeF = this -> getVertexNode(vertex);
        if (nodeF == 0) throw VertexNotFoundException(this -> vertex2Str(*nodeF));

        typename DLinkedList<typename AbstractGraph<T>::VertexNode*>::Iterator it;
        it = this -> nodeList.begin();
        while(it != this ->nodeList.end()){
            typename AbstractGraph<T>::VertexNode* nodeT = *it;
            typename AbstractGraph<T>::Edge* edge = nodeT -> getEdge(nodeF);
            if (edge != 0){
                nodeT -> removeTo(nodeF);
            }
            edge = nodeF ->getEdge(nodeT);
            if (edge != 0){
                nodeF -> removeTo(nodeT);
            }
            it++;
        }

        this -> nodeList.removeItem(nodeF);
    }
};

#endif /* DGRAPHMODEL_H */

