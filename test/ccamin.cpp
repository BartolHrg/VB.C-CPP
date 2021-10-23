
// #include <iostream>

    
// using namespace std;

// namespace my_own 
// {
    
//     template < typename a, typename b >
//     struct pair 
//     {
//         a first;
//         b second;
//     };
    
//     template <typename t>
//     class linkedlist
//     {
//         private:
//             void* head;
//             static  linkedlist<t>*  createfromarray (int size , t* arr)
//             {
//                 return nullptr;
//             }
//         protected:
//         public:
//             //friend function ...
//             bool operator << (t item) 
//             {
//                 return true;
//             }
//     };
 
// }

// int main () 
// {
//     my_own::linkedlist<int> llhaha;
//     cout << (llhaha << 9);
    
// }

using namespace std; namespace my_own { template < typename A, typename B > const struct Pair template <typename T> CLASS LinkedList { private: LinkedListNode* head; static LinkedList<T>* createFromArray (int size, T* arr) { return nullptr; } protected: public: bool operator << (T item) { return true; } }; } int main () { my_own::LinkedList<int> llhaha; cout << (llhaha << 9); }