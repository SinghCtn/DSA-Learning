#include<iostream>
using namespace std;

class Heap{
    private:
        int size;
        int *H;
        int l;
    
    public:
        Heap(int *A, int sz){
            size = sz;
            H = A;
            l = 0;
        }

        void Create(){
            l = 1;
            for(int i = 2; i < size; i++){
                Insert(i);
            }
        }

        void Insert(int i){
            int temp = H[i];
            while(i > 1 && temp > H[i/2]){
                H[i] = H[i/2];
                i = i/2;
            }
            H[i] = temp;
            l++;
        }

        int Delete(){
            int x = H[1];
            H[1] = H[l];
            int i = 1;
            int j = 2 * i;
            while(j < l){
                if(H[j+1] > H[j]){
                    j = j + 1;
                }
                if(H[j] > H[i]){
                    swap(H[j], H[i]);
                    i = j;
                    j = 2 * i;
                }
                else{
                    break;
                }
            }
            H[l] = x;
            l--;
            return x;
        }

        void HeapSort(){
            Create();
            for(int i = 1; i < size; i++){
                Delete();
            }
            Display();
        }

        void Display(){
            for(int i = 1; i < size; i++){
                cout<<H[i]<<" ";
            }
            cout<<endl;
        }
};


int main(){
    int A[] = {0, 10, 20, 30, 25, 5, 40, 35};
    Heap h( A, 8);
    h.HeapSort();
    // h.Create();
    // h.Display();
    // cout<<h.Delete()<<endl;
    // h.Display();
    // cout<<h.Delete()<<endl;
    // h.Display();
    // cout<<h.Delete()<<endl;
    // h.Display();
    // cout<<h.Delete()<<endl;
    // h.Display();
    // cout<<h.Delete()<<endl;
    // h.Display();

    return 0;
}