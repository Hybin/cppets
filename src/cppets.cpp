#include "cppets.hpp"

using namespace std;

struct cppets::ListNode {
    int val;
    ListNode *next;

    // constructor
    ListNode(int x) : val(x), next(NULL) {};
};

class cppets::UnionFind {
public:
    UnionFind(int n) {
        this->count = n;
        this->parent = new int[n];
        this->size = new int[n];

        for (int i = 0; i < n; ++i) {
            this->parent[i] = i;
            this->size[i] = 1;
        }
    }

    void connect(int p, int q) {
        int rootP = this->find(p);
        int rootQ = this->find(q);
        if (rootP == rootQ) {
            return;
        }
        
        // 小树接到大树下面，较平衡
        if (this->size[rootP] > this->size[rootQ]) {
            this->parent[rootQ] = rootP;
            this->size[rootP] += this->size[rootQ];
        } else {
            this->parent[rootP] = rootQ;
            this->size[rootQ] += this->size[rootP];
        }
        this->count--;
    }

    int find(int x) {
        while (this->parent[x] != x) {
            // 进行路径压缩
            this->parent[x] = this->parent[this->parent[x]];
            x = this->parent[x];
        }
        return x;
    }

    bool connected(int p, int q) {
        int rootP = this->find(p);
        int rootQ = this->find(q);
        return rootP == rootQ;
    }

    int getCount() {
        return this->count;
    }
private:
    int count;
    int *parent;
    int *size;
};

vector<string> cppets::split(const string &str, const string &delimiter) {
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

bool cppets::isPrime(int &n) {
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

std::string cppets::trim(std::string &str) {
    if (str.empty()) {
        return str;
    }
    
    const std::string space = " ";
    str.erase(0, str.find_first_not_of(space));
    str.erase(str.find_last_not_of(space) + 1);
    
    return str;
}

cppets::ListNode* cppets::reverseListNode(cppets::ListNode *head) {
    cppets::ListNode *prev = NULL, *curr = head;

    while (curr != NULL) {
        cppets::ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}
