//
//  main.cpp
//  SortMethods
//
//  Created by YunHua Tung on 2019/4/8.
//  Copyright © 2019 YunHua Tung. All rights reserved.
//
using namespace std;
#include <iostream>

void SSwap(int* _a, int* _b){
    int temp=*_a;
    *_a=*_b;
    *_b=temp;
}
void printArray(int* _arr, int _size){
    for(int i=0;i<_size;i++){
        cout<<_arr[i];
        if(i!=(_size-1)){
            cout<<"->";
        }
    }
    cout<<endl;
}
void bubbleSort(int* _arr,int _size){
    for(int i=0;i<_size;i++){
        for(int j=i+1;j<_size;j++){
            if(_arr[i]>_arr[j]){
                SSwap(&_arr[i],&_arr[j]);
            }
        }
    }
}

void selectionSort(int* _arr,int _size){
    for(int i=0;i<_size;i++){
        int smallIndex=i;
        for(int j=i+1;j<_size;j++){
            if(_arr[j]<_arr[smallIndex]){
                smallIndex=j;
            }
        }
        SSwap(&_arr[i], &_arr[smallIndex]);
    }
}

void insertSort(int* _arr, int _size){
    for(int i=1;i<_size;i++){
        int temp=_arr[i];
        int j=i-1;
        while(_arr[j]>temp){
            _arr[j+1]=_arr[j];
            j--;
        }
        _arr[j+1]=temp;
    }
}
void merge(int* _arr, int _front, int _end, int _mid){
    int _l_size=_mid-_front+2;
    int _r_size=_end-_mid+1;
    int* _l_arr = new int[_l_size];
    int* _r_arr = new int[_r_size];
    for(int i=0;i<_l_size-1;i++){
        _l_arr[i]=_arr[_front+i];
    }
    for(int i=0;i<_r_size-1;i++){
        _r_arr[i]=_arr[_mid+i+1];
    }
    _l_arr[_l_size-1]=12345678;
    _r_arr[_r_size-1]=12345678;
    int i=0,j=0;
    for(int _compare=_front;_compare<=_end;_compare++){
        if(_l_arr[i]<=_r_arr[j]){
            _arr[_compare]=_l_arr[i];
            i++;
        }else{
            _arr[_compare]=_r_arr[j];
            j++;
        }
    }
    
    
}

void mergedSort(int* _arr, int _front, int _end){
    int _mid=(_front+_end)/2;
    if(_front<_end){
        mergedSort(_arr,_front,_mid);
        mergedSort(_arr, _mid+1, _end);
        merge(_arr, _front, _end, _mid);
    }
    
}

void quickSort(int* _arr, int _front, int _end){
    int _pivot=_arr[_end];
    if(_front<_end){
        int small=_front-1;
        for(int j=_front;j<_end;j++){
            if(_arr[j]<_pivot){
                small++;
                SSwap(&_arr[small],&_arr[j]);
            }
        }
        small++;
        SSwap(&_arr[_end], &_arr[small]);
        quickSort(_arr, _front, small-1);
        quickSort(_arr, small+1, _end);
    }
    
}
void maxHeapify(int* _arr, int _root, int _size){
    int _large=_root;
    int _left=2*_root+1;
    int _right=2*_root+2;
    if(_left<_size && _arr[_left]>_arr[_large]){
        _large=_left;
    }
    if(_right<_size && _arr[_right]>_arr[_large]){
        _large=_right;
    }
    if(_large!=_root){
        SSwap(&_arr[_root], &_arr[_large]);
        maxHeapify(_arr, _large, _size);
    }
}


void heapSort(int* _arr, int _size){
    for(int i=_size/2-1;i>=0;i--){
        maxHeapify(_arr, i, _size);
    }
    for(int i=_size-1;i>=0;i--){
        SSwap(&_arr[0], &_arr[i]);
        maxHeapify(_arr, 0, i);
    }
   
    
}

int binarySearch(int* _arr, int _value, int _size){
    int front=0, end=_size-1;
    while(front<=end){
        int mid=(front+end)/2;
        if(_arr[mid]<_value){
            front=mid+1;
        }else  if(_arr[mid]>_value){
            end=mid-1;
        }else{
            return mid;
        }
    }
    return -1;
}
int selection(int* _arr,int order,int _size){
    quickSort(_arr,0,order);
    for(int i=order;i<_size;i++){
        if(_arr[i]<_arr[order-1]){
            SSwap(&_arr[i], &_arr[order-1]);
            quickSort(_arr,0,order);
        }
    }
    return _arr[order-1];
    
}

int main(int argc, const char * argv[]) {
    int arr[]={56,12,24,3,90,45,67,51,99,38,72,69,21,87,-7};
    int size=sizeof(arr)/sizeof(arr[0]);
    int order=selection(arr,8,size);
    cout<< "The 8th big:"<<order<<endl;
//    insertSort(arr, _size);
//    bubbleSort(arr, size);
//    selectionSort(arr, size);
//    mergedSort(arr, 0, size-1);
//    quickSort(arr, 0, size-1);
    heapSort(arr,size);
    printArray(arr, size);
    int key=binarySearch(arr, -7,size);
    if(key>=0){
        cout<<"found! Index:"<<key<<endl;
    }else{
        cout<<"not found"<<endl;
    }
    
    return 0;
}

