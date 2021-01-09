#include "cppets.hpp"

using namespace std;

namespace cppets {
    vector<string> split(const string &str, const string &delimiter) {
        vector<string> result;
        string::size_type start = 0, end = str.find(delimiter);

        while (end != string::npos) {
            result.push_back(str.substr(start, end - start));

            start = end + delimiter.size();
            end = str.find(delimiter, start);
        }

        if (start != str.length()) {
            result.push_back(str.substr(start));
        }

        return result;
    }

    bool isPrime(int &n) {
        if (n <= 3) return n > 1;
        
        if (n % 6 != 1 && n % 6 != 5) return false;
        
        int s = sqrt(n);
        for (int i = 5; i <=s; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        
        return true;
    }

    ListNode* reverseListNode(ListNode *head) {
        ListNode *prev = NULL, *curr = head;

        while (curr != NULL) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    std::string trim(std::string &str) {
        if (str.empty()) {
            return str;
        }
    
        const std::string space = " ";
        str.erase(0, str.find_first_not_of(space));
        str.erase(str.find_last_not_of(space) + 1);
    
        return str;
    }
}
