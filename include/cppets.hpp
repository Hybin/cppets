#ifndef _CPPETS_HPP_
#define _CPPETS_HPP_

#include <vector>
#include <string>
#include <cmath>

struct ListNode {
    int val;
    ListNode *next;

    // constructor
    ListNode(int x) : val(x), next(NULL) {};
};

namespace cppets {
    // split the string with specific delimiter
    std::vector<std::string> split(const std::string &str, const std::string &delimiter);
    
    // check if the number is a prime
    bool isPrime(int &n);

    // reverse the ListNode
    ListNode* reverseListNode(ListNode *head);
    
    // trim the string
    std::string trim(std::string &str);
}

#endif