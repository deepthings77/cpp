#include<iostream>
using namespace std;
class Student{
    public:
    int roll_n,semester;
    string name;
    float cgpi;
    void SetDetails(){
        cout<<"Enter the Name:";
        cin>>name;
        cout<<"\n Enter roll number:";
        cin>>roll_n;
        cout<<"\n Enter semester:";
        cin>>semester;
        cout<<"\n Enter the cgpi:";
        cin>>cgpi;
    }
    void GetDetails(float k){
        if(cgpi>k){
        cout<<roll_n<<"\t"<<semester<<"\t"<<name<<"\t"<<cgpi<<endl;
    }
    }
   
};
  Student S[6];
 void insertion(Student S[] , int position , Student &newStudent)
 {
        if(position >= 0 && position <=5 )
       { for (int i = 4; i >= position; i--) {
            S[i + 1] = S[i]; 
        }
        S[position] = newStudent;
        }
 }

int main(){
  
    for(int i=0;i<5;i++){
        S[i].SetDetails();
    }
    float k;
    cout<<"\nEnter the value of min cgpi: ";
    cin>>k;
    for(int i=0;i<5;i++){
        S[i].GetDetails(k);
    }
    int x;
    cout<<"Enter the index value:";
    cin>>x;
    Student newStudent;
    newStudent.SetDetails();
    insertion(S,x,newStudent);
    for(int i=0;i<6;i++){
       cout<< S[i].name << endl;
    }
    
    
}