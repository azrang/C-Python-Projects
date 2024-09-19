// THIS IS THE PROVIDED CODE FOR PROGRAM #2, DSA 1, FALL 2022

#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

// A simple class; each object holds four public fields
class Data {
public:
  string lastName;
  string firstName;
  string ssn;
};

// Load the data from a specified input file
void loadDataList(list<Data *> &l, const string &filename) {

  ifstream input(filename);
  if (!input) {
    cerr << "Error: could not open " << filename << "\n";
    exit(1);
  }

  // The first line indicates the size
  string line;
  getline(input, line);
  stringstream ss(line);
  int size;
  ss >> size;

  // Load the data
  for (int i = 0; i < size; i++) {
    getline(input, line);
    stringstream ss2(line);
    Data *pData = new Data();
    ss2 >> pData->lastName >> pData->firstName >> pData->ssn;
    l.push_back(pData);
  }

  input.close();
}

// Output the data to a specified output file
void writeDataList(const list<Data *> &l, const string &filename) {

  ofstream output(filename);
  if (!output) {
    cerr << "Error: could not open " << filename << "\n";
    exit(1);
  }

  // Write the size first
  int size = l.size();
  output << size << "\n";

  // Write the data
  for (auto pData:l) {
    output << pData->lastName << " " 
	   << pData->firstName << " " 
	   << pData->ssn << "\n";
  }

  output.close();
}

// Sort the data according to a specified field
// (Implementation of this function will be later in this file)
void sortDataList(list<Data *> &);
int filetype(const string &filename, const list<Data *> &l);

// The main function calls routines to get the data, sort the data,
// and output the data. The sort is timed according to CPU time.
int main() {
  string filename;
  cout << "Enter name of input file: ";
  cin >> filename;
  list<Data *> theList;
  loadDataList(theList, filename);

  cout << "Data loaded.\n";

  cout << "Executing sort...\n";
  clock_t t1 = clock();
  sortDataList(theList);
  clock_t t2 = clock();
  double timeDiff = ((double) (t2 - t1)) / CLOCKS_PER_SEC;

  cout << "Sort finished. CPU time was " << timeDiff << " seconds.\n";


  cout << "Enter name of output file: ";
  cin >> filename;
  writeDataList(theList, filename);

  return 0;
}

// -------------------------------------------------
// YOU MAY NOT CHANGE OR ADD ANY CODE ABOVE HERE !!!
// -------------------------------------------------

// You may add global variables, functions, and/or
// class defintions here if you wish.


bool t1(Data* current,Data* next){;
    int ln = current->lastName.compare(next->lastName);
    if(ln == 0){
        int fn = current->firstName.compare(next->firstName);
        if(fn == 0){
            int ssn = current->ssn.compare(next->ssn);
            if(ssn < 0){
                return true;
            } else {
                return false;
            }
        } else if(fn < 0){
            return true;
        } else {
            return false;
        }
    } else if(ln < 0){
        return true;
    } else {
        return false;
    }

}
//seperate function for when it is t4
bool t4(Data* current,Data* next){
    int ssn = current->ssn.compare(next->ssn);
            if(ssn < 0){
                return true;
            } else {
                return false;
            }
}

Data* arr[10100001];

void sortDataList(list<Data *> &l) {
  string firstLn = l.front()->lastName;
  string firstFn = l.front()->firstName;
  string lastLn = l.back()->lastName;
  string lastFn = l.front()->firstName; 
  int size= l.size();
  auto lptr= l.begin();
  for (int i=0; i< size; i++){
    arr[i]=*(lptr++);
  }
  if(firstLn == lastLn && firstFn == lastFn){
      sort(arr, arr+size,t4); //input shld be compare function
  } else {
      sort(arr, arr+size, t1);// else sort other datasets
  }
  lptr=l.begin();
  for (int p=0; p<size; p++){
    *(lptr++)=arr[p];
  }
}

