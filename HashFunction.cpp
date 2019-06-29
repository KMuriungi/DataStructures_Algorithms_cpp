#include <iostream>
#include <unordered_map>
#include <string>
#include <functional>

using namespace std;

/*
Hash Function Properties:

Deterministic: A given input must always generate the same output (i.e no randomness)

Uniform: The output of a hash function should  be roughly equally probable in the range.

*/

//DJB Hash Function: from Daniel J. Bernstein, originally posted to the newsgroup comp.lang.c

size_t djb_hash(const string& str){
    size_t hash = 5381; //"Initial Value" or "Magic Constant" == 5381

    for (size_t i = 0; i < str.length(); i++){
        hash = ((hash << 5) + hash) + str[i]; // = 33 * hash + str[i]
    }
    return hash;
}

int main(){
    //1. Test our custom hash function
    cout << "djb hash: " << hex << djb_hash("MURIUNGi") << endl;

    //2. Test the built-in std::hash for strings (Fowler-Noll-Vo or FNV Hash in Microsoft C++)
    cout << "std::has: " << hex << std::hash<string>()("MURIUNGi") << endl;

    //3. Hash function for unordered_map<string, string>
    unordered_map<string, string> m1;
    unordered_map<string, string>::hasher hash_func = m1.hash_function();
    cout << "unordered_map hasher: " <<hex << hash_func("MURIUNGi") << "\n\n";

    //4. Replace Hasher
    unordered_map<string, string, function<decltype(djb_hash)>> m2(10, djb_hash);
    m2["MURIUNGi"] = "OK";
    cout << m2["MURIUNGi"] << endl;

    return 0;
}
