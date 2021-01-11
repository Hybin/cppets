#ifndef _CPPETS_HPP_
#define _CPPETS_HPP_

#include <vector>
#include <string>
#include <cmath>

namespace cppets {
    // split the string with specific delimiter
    std::vector<std::string> split(const std::string &str, const std::string &delimiter);
    
    // check if the number is a prime
    bool isPrime(int &n);
    
    // trim the string
    std::string trim(std::string &str);

    struct ListNode;

    // reverse the ListNode
    ListNode* reverseListNode(ListNode *head);

    class UnionFind;
}

#endif