#include <iostream>
#include <vector>
using namespace std;
bool IsAlreadyInArray(vector <int>v, int data){
    
    if (v.empty())
        return false;
    for (int i=0; i<v.size();i++)
    {
        if (v[i]==data)
            return true;
    }
    return false;
}

int * remove (int *head, int size){
    int * prtH = head;
    int * prtN = NULL;
    std::vector <int> v;
    
    if (head == NULL)
        return head;
    else if (size<=1 && size>=0)
        return head;
    
    else {
        
        for (int i=0; i<size;i++)
            if (!IsAlreadyInArray(v, prtH[i]))
                v.push_back(prtH[i]);
    }
    if (v.size()>=1)
    {
        prtN=(int*) malloc(  sizeof(int) * v.size());
        for (int i =0;i<v.size();i++){
            prtN[i] = v[i];
            printf("%d", prtN[i]);
        }
        return prtN;
    }
    
    return head;
    
    
}



int main(){
    
      int array [] ={1,2,3,4,5,4,5,1,2,3,1};
    // int *array = NULL;
    // int array[] = {1};
    
    printf ("result of fuction is %d\n",*remove(array, sizeof(array)/sizeof(int)));
    
    return 0;
}
