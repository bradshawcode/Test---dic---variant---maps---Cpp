#include <iostream>
#include <string>
#include <variant>
#include <map>

using namespace std;

int main()
{
    variant <string, int> data;
    map<string, variant <string, int>> value;

    // first insert function version (single parameter):
    value.insert(pair<string, int>("age", 100));

    for (int i = 0; i < 100; i++) {
        value.insert(pair<string, int>(to_string(i), i));
    }
    for (int i = 0; i < 100; i++) { //Dic management.
        //Coverts i to string.
        cout << get<int>(value[to_string(i)]) << endl; //gets the value at i;
    }

    cout << get<int>(value["age"]) << endl; //gets the value at age.
    
    data = 1;
    data = string("hello world!");

    if (auto value = get_if<string>(&data)) {
    
        string& returnType = *value;//Gets the value from the memory addresss.
        cout << "returnType: " << returnType << endl;
    }
    else if (auto value = get_if<int>(&data)) {
        //String get value;
        //string returnType = get<string>(data);
        
        //Int get value;
        int returnType = get<int>(data);
        cout << "returnType: " << returnType << endl;
        //int& returnType = *value;//Gets the value from the memory addresss.
    }

    int vr = 0;
    int* v = &vr; //gets memory address
    cout << v << endl; //Prints memory address.
    cout << *v << endl; // returns the value at the pointer address v
    return 0;
}
