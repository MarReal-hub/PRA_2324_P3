
#include <iostream>
#include "BSTreeDict.h"

int main() {
    BSTreeDict<int> dict;

    std::cout << "Insertando...\n";
    dict.insert("One", 1);
    dict.insert("Two", 2);
    dict.insert("Three", 3);
    dict.insert("Four", 4);

    std::cout << "entries(): " << dict.entries() << "\n";
    std::cout << "search('Two'): " << dict.search("Two") << "\n";

    std::cout << "BST (inorder): " << dict << "\n";

    std::cout << "remove('One') => " << dict.remove("One") << "\n";
    std::cout << "entries(): " << dict.entries() << "\n";
    std::cout << "BST (inorder): " << dict << "\n";

    try {
        dict.insert("Two", 22); // duplicada: debe lanzar
        std::cout << "ERROR: no lanzó en insert('Two')\n";
    } catch (std::runtime_error& e) {
        std::cout << "OK: insert('Two') lanzó: " << e.what() << "\n";
    }

    try {
        dict.search("Ten"); // inexistente: debe lanzar
        std::cout << "ERROR: no lanzó en search('Ten')\n";
    } catch (std::runtime_error& e) {
        std::cout << "OK: search('Ten') lanzó: " << e.what() << "\n";
    }

    try {
        dict.remove("Ten"); // inexistente: debe lanzar
        std::cout << "ERROR: no lanzó en remove('Ten')\n";
    } catch (std::runtime_error& e) {
        std::cout << "OK: remove('Ten') lanzó: " << e.what() << "\n";
    }

    return 0;
}

