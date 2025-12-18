#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>
#include <ostream>

/**
 * @brief Par clave-valor para el diccionario.
 *
 * @tparam V Tipo del valor asociado a la clave.
 *
 * Comparación:
 *   - La relación de orden se define EXCLUSIVAMENTE por la clave (key),
 *     usando el orden lexicográfico de std::string.
 */
template <typename V>
class TableEntry {
public:
    // --- Datos públicos (según la práctica) ---
    std::string key;  ///< Clave
    V value;          ///< Valor asociado

    // --- Constructores ---
    TableEntry() = default;

    // Constructor clave-valor (habitual para inserción)
    TableEntry(const std::string& k, const V& v) : key(k), value(v) {}

    // Constructor solo clave (útil para búsquedas/eliminación)
    explicit TableEntry(const std::string& k) : key(k), value(V{}) {}

    // --- Comparación por clave (lexicográfica) ---
    friend bool operator<(const TableEntry<V>& te1, const TableEntry<V>& te2) {
        return te1.key < te2.key;   // usa std::string::operator<
    }

    friend bool operator>(const TableEntry<V>& te1, const TableEntry<V>& te2) {
        return te1.key > te2.key;   // usa std::string::operator>
    }

    // (Opcional, pero útil) igualdad por clave
    friend bool operator==(const TableEntry<V>& te1, const TableEntry<V>& te2) {
        return te1.key == te2.key;
    }

    // (Opcional) salida para depuración/imprimir
    friend std::ostream& operator<<(std::ostream& out, const TableEntry<V>& te) {
        // Imprime "key:value" si V es imprimible; si no, al menos la clave.
        out << te.key;
        return out;
    }
};

#endif // TABLEENTRY
