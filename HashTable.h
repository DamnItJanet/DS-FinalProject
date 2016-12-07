#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <functional>

template<class T>
class HashEntry
{
    public:
        HashEntry(int key, T val)
        {
            this->key = key;
            this->value = val;
        }

        ~HashEntry() {}

        int getKey()
        {
            return key;
        }

        T getValue()
        {
            return value;
        }

    private:
        T value;
        int key;
};

template<class T>
class HashTable
{
    public:
        HashTable(int size)
        {
            tableSize = size;
            table = new HashEntry<T>*[tableSize];

            for (int i = 0; i < tableSize; i++)
                table[i] = NULL;
        }

        ~HashTable()
        {
            delete[] table;
        }

        T getElement(int key)
        {
            return table[key];
        }

        // Use standard hash function
        void addElement(int key, T value)
        {
            int hash = (key % tableSize);

            while (table[hash] != NULL && table[hash]->getKey() != key)
                hash = (hash + 1) % tableSize;

            if (table[hash] != NULL)
                delete table[hash];

            table[hash] = new HashEntry<T>(key, value);
        }

    private:
        HashEntry<T>** table;
        int tableSize;
};

#endif // HASHTABLE_H
