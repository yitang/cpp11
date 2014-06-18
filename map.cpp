// practise c++11: conver a data table into std::map<string, vector<double> >
// 08 Apr 2014, yi tang 

// data import: plain format,  cells are deliminated by space/tab/new line. every single cell is readed in as string, then convert to int/float/double via std::sto(f, d, xx). 
// the trick is to new the number of rows/cols, and also #cols of ids (at least 1). then the rest will be allocated to 'value' in std::map. 
// hazard.find("xxx locator") will gives a std::vector<double>, that will be used for ADRG calculation. 

#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <map>
#include <fstream>

using namespace std;

template<class T>
inline void read(std::vector<T>& v, std::string file){
    std::ifstream input {file};
    std::vector<T> value {std::istream_iterator<T> {input}, std::istream_iterator<T>{}};
    v = value;
};

template<class T>
inline void printElem(const std::vector<T>& v){
    for (const auto& x : v)
        std::cout << x << "\t";
    std::cout << std::endl;
}


int main(){
    vector<string> input;
    read(input, "data.dat");
  
    printElem(input);

    int nrow = 8, ncol = 18; // first two columns are ids. 

    vector<string> id1, id2;
    vector<double> value;
    for (int i = 0; i < input.size(); i++){
        if (i%ncol == 0){
            id1.push_back(input[i]);
            continue;
        }
        else if (i%ncol == 1){
            id2.push_back(input[i]);
            continue;
        }
        else 
            value.push_back(stod(input[i])); // stod: sring to double. 
    
    }
  
    for (int i =0; i < id1.size(); i++){
        id1[i].append(id2[i]); // combine two ids into one. 
    }
    printElem(id1);

    printElem(value);


// construct map<string, vector<double> > via list initialization. 
    std::map<std::string, vector<double> > hazard;
  
    for (int i = 0; i < id1.size(); i++){
        vector<double> value_tmp(ncol - 2); 
        copy(value.begin() + i*ncol - 2, value.begin() + (i+1)*ncol - 2, value_tmp.begin());
        hazard.insert({id1[i], {value_tmp}});
    }


    auto x = hazard.find("CO111QG");
    if (x!= hazard.end())
        std::cout << "CO111QG has value";
    printElem(x->second);


}
