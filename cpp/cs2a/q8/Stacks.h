// Student ID: 20670918
//
#ifndef Stacks_h
#define Stacks_h

#include <vector>
#include <sstream>
#include <iostream>

class Stack_Int {
private:
    std::vector<int> _data;

public:
    // No explicit constructor or destructor
    size_t size() const {
        return _data.size();
    }

    bool is_empty() const {
        return _data.empty();
    }

    void push(int val) {
        _data.push_back(val);
    }

    int top(bool& success) const {
        if (is_empty()) {
            success = false;
            return 0;
        } else {
            success = true;
            return _data.back();
        }
    }

    bool pop() {
        if (!is_empty()) {
            _data.pop_back();
            return true;
        } else {
            return false;
        }
    }

    bool pop(int& val) {
        bool temp;
        val = top(temp);
        return pop();
    }

    std::string to_string() const {
        std::string rv("");
        std::ostringstream oss;
        size_t count = 10;
        size_t idx = size();

        oss << size();
        rv += "Stack (" + oss.str() + " elements):\n";

        while (count > 0 && idx > 0) {
            idx--; count--;
            oss.clear();
            oss.str("");
            oss << _data[idx];
            rv +=  oss.str() + "\n"; 
        }
    
        if (idx != 0) {
            rv += "...\n";
        }

        rv += "Elements, if listed above, are in increasing order of age.";
        return rv;
    }

    // Don't remove the following line
    friend class Tests;
};

class Stack_String {
private:
    std::vector<std::string> _data;

public:
    // No explicit constructor or destructor
    size_t size() const {
        return _data.size();
    }

    bool is_empty() const {
        return _data.empty();
    }

    void push(std::string val) {
        _data.push_back(val);
    }

    std::string top(bool& success) const {
        if (is_empty()) {
            success = false;
            return 0;
        } else {
            success = true;
            return _data.back();
        }
    }

    bool pop() {
        if (!is_empty()) {
            _data.pop_back();
            return true;
        } else {
            return false;
        }
    }

    bool pop(std::string& val) {
        bool temp;
        val = top(temp);
        return pop();
    }

    std::string to_string() const {
        std::string rv("");
        std::ostringstream oss;
        size_t count = 10;
        size_t idx = size();

        oss << size();
        rv += "Stack (" + oss.str() + " elements):\n";

        while (count > 0 && idx > 0) {
            idx--; count--;
            rv += _data[idx] + "\n"; 
        }
    
        if (idx != 0) {
            rv += "...\n";
        }

        rv += "Elements, if listed above, are in increasing order of age.";
        return rv;
    }

    // Don't remove the following line
    friend class Tests;
};

#endif /* Stacks_h */