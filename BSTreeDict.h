
#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include <string>

#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

// -----------------------------------------------------------------------------
// Operadores de comparación para TableEntry<V>:
// El BSTree necesita < y > para decidir si baja por la izquierda o la derecha.
// Ordenamos por la 'key' (lexicográfico).
// -----------------------------------------------------------------------------
template <typename V>
inline bool operator<(const TableEntry<V>& a, const TableEntry<V>& b) {
    return a.key < b.key;
}

template <typename V>
inline bool operator>(const TableEntry<V>& a, const TableEntry<V>& b) {
    return a.key > b.key;
}

// -----------------------------------------------------------------------------
// Diccionario basado en BST: almacena pares (key, value) dentro de TableEntry<V>
// usando BSTree<TableEntry<V>> como estructura subyacente.
// -----------------------------------------------------------------------------
template <typename V>
class BSTreeDict : public Dict<V> {
private:
    BSTree<TableEntry<V>> bst;

public:
    BSTreeDict() = default;
    ~BSTreeDict() = default;

    // Nº de entradas almacenadas
    int entries() override {
        return bst.size();
    }

    // Inserta un (key, value). Lanza std::runtime_error si la clave ya existe.
    void insert(std::string key, V value) override {
        TableEntry<V> te(key, value);
        bst.insert(te);
    }

    // Busca por clave y devuelve el valor. Lanza std::runtime_error si no existe.
    V search(std::string key) override {
        TableEntry<V> query(key);           // value por defecto; buscamos por la 'key'
        TableEntry<V> found = bst.search(query);
        return found.value;
    }

    // Elimina por clave y devuelve el valor borrado.
    // Si la clave no existe, lanza std::runtime_error.
    V remove(std::string key) override {
        TableEntry<V> query(key);
        // Primero obtenemos el valor para poder devolverlo (BSTree::remove devuelve void).
        V val = bst.search(query).value;
        bst.remove(query);
        return val;
    }

    // Impresión: delega en el operador << del BSTree, que hace recorrido inorder.
    friend std::ostream& operator<<(std::ostream& out, const BSTreeDict<V>& dict) {
        out << dict.bst;
        return out;
    }
};

#endif // BSTREEDICT_H

