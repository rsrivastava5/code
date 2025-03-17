// Student ID: 20670918
// TODO - Type in your student ID after the colon above.
// String_List.h
//
#ifndef String_List_h
#define String_List_h

#include <iostream>
#include <sstream>

// Important implementation note: With the exception of to_string(),
// find*() and clear(), all list methods below should operate in a constant amount
// of time regardless of the size of the String_List instance.
//
// The semantics of _prev_to_current is such that it always points to the
// node *BEFORE* the current one. This makes the manipulations easy because
// we can only look forward (and not back) in singly linked lists.
//
// I've included some method header comments below where there's likely to
// be confusion.
//
class String_List {
private:
    struct Node {
        std::string data;
        Node *next;
        Node(std::string s = "") : data(s), next(nullptr) {}
    };

    Node *_head, *_tail, *_prev_to_current;
    size_t _size;

public:
    String_List() {
        _head = new Node("_SENTINEL_");
        _tail = _head;
        _prev_to_current = _head;
        _size = 1;
    }

    ~String_List() {
        clear();
        delete _head;
        _head = nullptr;
        _tail = nullptr;
        _prev_to_current = nullptr;
        _size = 0;
    }

    String_List *insert_at_current(std::string s) {
        Node *temp = new Node(s);

        if (_prev_to_current == _tail)
            _tail = temp;
        temp->next = _prev_to_current->next;
        _prev_to_current->next = temp;
        _prev_to_current = temp;
        ++_size;
    
        return this;
    }

    String_List *push_back(std::string s) {
        Node *temp = _prev_to_current;
        _prev_to_current = _tail;
        insert_at_current(s);
        _prev_to_current = temp;
        ++_size;

        return this;
    }

    String_List *push_front(std::string s) {
        Node *temp = _prev_to_current;
        _prev_to_current = _head;
        insert_at_current(s);
        _prev_to_current = temp;
        ++_size;

        return this;
    }

    String_List *advance_current() {
        if (_prev_to_current == _tail)
            return nullptr;
        _prev_to_current = _prev_to_current->next;

        return this;
    }

    std::string get_current() const {
        if (_prev_to_current->next == nullptr)
            return _head->data;
        return _prev_to_current->next->data;
    }

    String_List *remove_at_current() {
        if (_prev_to_current != _tail) {
            Node *temp = _prev_to_current->next;
            _prev_to_current->next = _prev_to_current->next->next;
            delete temp;
            _size--;
        }
    
        return this;
    }

    size_t get_size() const {
        return _size;
    }

    String_List *rewind() {
        _prev_to_current = _head;

        return this;
    }

    void clear() {
        rewind();
        while (_head != _tail)
            remove_at_current();
    }

    // Find a specific item. Does NOT change cursor.
    //
    // The following returns a reference to the target string if found. But what will
    // you do if you didn't find the requested string? Using sentinel markers is
    // one way to handle that situation. Usually there's only one copy of the
    // sentinel that's global. We will use a local one so it's cleaner with a
    // little more risk (what's the risk?)
    //
    std::string& find_item(std::string s) const {
        Node *curr = _head;
        while (curr != _tail) {
            if (curr->next->data == s)
                return curr->next->data;
            curr = curr->next;
        }
    
        return _head->data;
    }

    // Print up to max_lines lines starting at _prev_to_current->next. If the caller
    // wants to print from the beginning of the list, they should rewind() it first.
    //
    std::string to_string() const {
        std::string rv("");
        std::ostringstream oss;
        size_t count = 25;
        Node *curr = _prev_to_current;

        oss << get_size();
        rv += "# String_List - " + oss.str() + " entries total. Starting at cursor:\n";
        while (count > 0 && curr != _tail) {
            count--;
            curr = curr->next;
            rv += curr->data + '\n';
        }
        if (curr != _tail)
            rv += "...\n";

        return rv;
    }

    friend class Tests; // Don't remove this line
};

#endif /* String_List_h */