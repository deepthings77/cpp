// // #include<bits/stdc++.h> 
// // using namespace std;

// // class QueueNode
// // {
// //  public: 
// //     int val;
// //     QueueNode *next;
// //     QueueNode(int data)
// //     {
// //        val = data;
// //        next = nullptr;
// //     }
// // };  
// // QueueNode *Front = nullptr, *Rare = nullptr;

// // class Queue
// // {
// // public:
// //     int size = 0;
// //     bool Empty();
// //     void Enqueue(int value);
// //     void Dequeue();
// //     int Peek();
// // };  
// // bool Queue ::  Empty()
// // {
// //     return Front == nullptr;
// // }  
// // int Queue :: Peek()
// // {
// //     if(Empty())  
// //      {  cout<<"Queue is Empty"<<endl;
// //         return -1;
// //      } 
// //     else 
// //       return Front->val;
// // }   
// // void Queue :: Enqueue(int value)
// // {
// //     QueueNode *Temp;
// //     Temp = new QueueNode(value); 
// //     if (Temp == nullptr)  //When heap exhausted 
// //         cout << "Queue is Full" << endl;
// //     else
// //     {
// //         if (Front == nullptr)
// //         {
// //             Front = Temp;
// //             Rare = Temp;
// //         } 
// //         else
// //         {
// //             Rare->next = Temp;
// //             Rare = Temp;
// //         }
// //         cout<<value <<" Inserted into Queue "<<endl;
// //         size++;
// //     } 
// // }      
// // void Queue :: Dequeue() 
// // {
// //     if (Front == nullptr) 
// //         cout << "Queue is Empty" << endl;
// //     else
// //     { 
// //         cout<<Front->val <<" Removed From Queue"<<endl;
// //         QueueNode *Temp = Front;
// //         Front = Front->next;
// //         delete Temp;
// //         size--;
// //     }  
// // }   
// // int main()

// // {
// //     Queue Q;
// //     Q.Enqueue(10);
// //     Q.Enqueue(20);
// //     Q.Enqueue(30);
// //     Q.Enqueue(40);
// //     Q.Enqueue(50);
// //     Q.Dequeue();
// //     cout<<"The size of the Queue is "<<Q.size<<endl;
// //     cout<<"The Peek element of the Queue is "<<Q.Peek()<<endl;
// //     return 0;
// // }   



// #include<bits/stdc++.h>

// using namespace std;
// class Queue {
//   int * arr;
//   int start, end, currSize, maxSize;
//   public:
//     Queue() {
//       arr = new int[16];
//       start = -1;
//       end = -1;
//       currSize = 0;
//     }

//   Queue(int maxSize) {
//     ( * this).maxSize = maxSize;
//     arr = new int[maxSize];
//     start = -1;
//     end = -1;
//     currSize = 0;
//   }
//   void push(int newElement) {
//     if (currSize == maxSize) {
//       cout << "Queue is full\nExiting..." << endl;
//       exit(1);
//     }
//     if (end == -1) {
//       start = 0;
//       end = 0;
//     } else
//       end = (end + 1) % maxSize;
//     arr[end] = newElement;
//     cout << "The element pushed is " << newElement << endl;
//     currSize++;
//   }
//   int pop() {
//     if (start == -1) {
//       cout << "Queue Empty\nExiting..." << endl;
//     }
//     int popped = arr[start];
//     if (currSize == 1) {
//       start = -1;
//       end = -1;
//     } else
//       start = (start + 1) % maxSize;
//     currSize--;
//     return popped;
//   }
//   int top() {
//     if (start == -1) {
//       cout << "Queue is Empty" << endl;
//       exit(1);
//     }
//     return arr[start];
//   }
//   int size() {
//     return currSize;
//   }

// };

// int main() {
//   Queue q(6);
//   q.push(4);
//   q.push(14);
//   q.push(24);
//   q.push(34);
//   cout << "The peek of the queue before deleting any element " << q.top() << endl;
//   cout << "The size of the queue before deletion " << q.size() << endl;
//   cout << "The first element to be deleted " << q.pop() << endl;
//   cout << "The peek of the queue after deleting an element " << q.top() << endl;
//   cout << "The size of the queue after deleting an element " << q.size() << endl;

//   return 0;
// }