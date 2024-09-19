//second programming assignement for DSA where data structures were created for stack and queues

#include<vector>
#include<string>
#include<fstream> 
#include<iostream>
#include<sstream>
#include<list>
#include<string>
using namespace std;

//abstract base class
template<typename T>
class SimpleList{
    protected:
        void insertnode_beg(T);
        void insertnode_end(T);
        //T removeNode(); //from beginning of list, of type T
    private:
        string name; //name of list
        struct Node{ //node structure
        //struct is used since default members are public
            T data;
            Node *next;  //struct pointer
        };
    public: 
        SimpleList(string name){ //this is the constructor, allocating nodes for head and tail
            this->name=name;
            head= NULL; 
            tail= NULL; //the first node will be the tail and head
        }
        string get_name(){
            return name;
        }
        T removeNode();
        int checkempty();
        //pure virtual functions that will be implemented in derived classes
        virtual void push(T)=0;
        virtual T pop()=0; 
        
        Node* head=NULL; //pointer to first on list
        Node* tail=NULL; //pointer to last on list
};

template <typename T> //need to declare before every function
void SimpleList<T>::insertnode_beg(T newElement){  //need template for newelement
    Node* newNode= new Node(); //struct pointer pointing to new element
    newNode->data= newElement; 
    newNode->next=head; 
    head=newNode; 
    if (tail==NULL){
        tail=newNode;
    }
}

template <typename T>
void SimpleList<T>::insertnode_end(T newElement){
//to keep constant time, do not want to traverse array
    Node* newNode= new Node();
    newNode->data= newElement;
    newNode->next=NULL; //set initial position to null
    if (tail==NULL){ 
    //if stack or queue is empty, then new node is front and rear
        head=newNode;
        tail=newNode;
    }
    else{
    //set address of new item to tail and make tail equal to new item
    tail->next=newNode;
    tail=newNode;
    }
}

template <typename T>
int SimpleList<T>::checkempty(){
    if(head==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

template <typename T>
T SimpleList<T>::removeNode(){  //delete node at beginning
    Node* temp=head;
    head=head->next;
    if (head==NULL){
        tail==NULL;
    }
    T newElement=temp->data;
    free(temp);
    return newElement;
} 

template <typename T>
class Stack:public SimpleList<T>{
    public:
        Stack(string name):SimpleList<T>(name){
//empty constructor
        }
        virtual void push(T newElement){
            this->Stack<T>::insertnode_beg(newElement);
        }
        virtual T pop(){
            return this->Stack<T>::removeNode();
        }
    //now call appropriate member functions of base class!
};

template <typename T>
class Queue:public SimpleList<T>{
    public:
        Queue(string name):SimpleList<T>(name){
//empty constructor
        }
        virtual void push(T newElement){
            this->Queue<T>::insertnode_end(newElement);
        }
        virtual T pop(){
            return this->Queue<T>::removeNode();
        }
    //now call appropriate member functions of base class!
};

template <typename T>
//need to search for a list with a specified name
SimpleList<T>* search(list<SimpleList<T>*> &listSL, string list_name){
    for(auto pt= listSL.begin(); pt!=listSL.end(); pt++){   //auto gets type, from beg of list to end
        string str1= (*pt)->get_name();
        string str2= list_name;
        if(str1.compare(str2)==0){
            return *pt; //calls get_name function which then will store the name of the list
        }
    }
    return NULL;
}

void ProcessCommand(){
    string output, input, s;
    cout<<"enter the name of your input file"<<endl;
    cin>>input;
    cout<<"enter the name of your output file"<<endl;
    cin>>output;
    ofstream out(output);
    ifstream in(input);
    //lists to store appropriate names, need to append to these lists
    list<SimpleList<int> *> listSLi; // all integer stacks and queues
    list<SimpleList<double> *> listSLd; // all double stacks and queues
    list<SimpleList<string> *> listSLs; // all string stacks and queues
    while(getline(in,s)){
        stringstream ss;
        string first, second, third; 
        ss<<s;
        ss>>first>>second>>third;
        SimpleList<int>* pSLi= search(listSLi, second);
        SimpleList<string>* pSLs= search(listSLs, second);
        SimpleList<double>* pSLd= search(listSLd, second);
        string type=second.substr(0,1); //first letter of second word
        if (first=="create"){
            //has third word that represents type of stack
            out<<"PROCESSING COMMAND: "<<s<<endl; 
            if (type=="i"){ //create integer list
                if (pSLi ==NULL){
                    if (third=="queue"){ //add the queue onto integer stack
                        pSLi= new Queue<int> (second);
                        listSLi.push_front(pSLi);
                    }
                    else{
                        pSLi= new Stack<int> (second);
                        listSLi.push_front(pSLi);
                    }
                }
                else {
                    out<<"ERROR: This name already exists!"<<endl;
                }
            }
            else if (type=="s"){ //create string list
                if (pSLs==NULL){
                    if (third=="queue"){ //add the queue onto integer stack
                        pSLs= new Queue<string>(second);
                        listSLs.push_front(pSLs);
                    }
                    else {
                        pSLs= new Stack<string>(second);
                        listSLs.push_front(pSLs);
                    }
                }
                else{
                    out<<"ERROR: This name already exists!"<<endl;
                }
            }
            else if(type=="d"){ //create doible list
                if (pSLd==NULL){
                    if (third=="queue"){ //add the queue onto integer stack
                        pSLd= new Queue<double>(second);
                        listSLd.push_front(pSLd);
                    }
                    else {
                        pSLd= new Stack<double>(second);
                        listSLd.push_front(pSLd);
                    }
                }
                else{
                    out<<"ERROR: This name already exists!"<<endl;
                }
            }
        }
        else if (first=="push"){
            //has third word that represents what is pushed
            out<<"PROCESSING COMMAND: "<<s<<endl;
            if(type=="i"){
                //SimpleList<int>* pSLi= search(listSLi, second);
                if (pSLi==NULL){
                    out<<"ERROR: This name does not exist!"<<endl;
                }
                else{
                    int i_data= std::stoi(third); 
    /*finds name of stack/queue in the integer list*/
                    pSLi->push(i_data); //knows because it's virtual
                }
            }
            else if(type=="d"){
                if (pSLd==NULL){
                    out<<"ERROR: This name does not exist!"<<endl;
                }
                else{
                    double d_data= std::stod(third); 
                    pSLd->push(d_data);
                }
            }
            else if (type=="s"){
                if (pSLs==NULL){ 
                    out<<"ERROR: This name does not exist!"<<endl;   
                }
                else {
                    string s_data= third;
                    pSLs->push(s_data);
                }  
            }
        }
        else if (first=="pop"){
            out<<"PROCESSING COMMAND: "<<first<< " " <<second<<endl;
            if(type == "i"){
                if(pSLi == NULL){
                    out<< "ERROR: This name does not exist!"<<endl;
    /* saving values to node, see push. find what is in stack*/
                }
                else if(pSLi->checkempty()){
                    out << "ERROR: This list is empty!"<<endl;
                }
                else if (pSLi!=NULL){
                    out << "Value popped: " << pSLi->pop() << endl;
                }
            }
            else if(type == "d"){
                //SimpleList<double>* pSLd = search(listSLd, second);
                if(pSLd == NULL){
                    out << "ERROR: This name does not exist!"<<endl;
                }
                else if(pSLd->checkempty()){
                    out << "ERROR: This list is empty!"<<endl;
                }
                else if (pSLd != NULL){
                    out << "Value popped: " << pSLd->pop() << endl;
                }
            }
            else if (type=="s"){
                //SimpleList<string>* pSLs = search(listSLs, second);
                if(pSLs == NULL){
                    out << "ERROR: This name does not exist!"<<endl;
                }
                else if(pSLs->checkempty()){
                    out << "ERROR: This list is empty!"<<endl;
                }
                else if (pSLs != NULL){
                    out << "Value popped: " << pSLs->pop() << endl;
                }
            }
        }
    }
out.close();
in.close();
}

int main() {
    string input;
    ProcessCommand();
}
