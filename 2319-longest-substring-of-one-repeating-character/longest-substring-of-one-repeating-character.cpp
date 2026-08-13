struct Node {
    int maxLen;   // Length of the longest repeating character substring in this segment
    int prefLen;  // Length of the repeating prefix
    int suffLen;  // Length of the repeating suffix
    char prefChar; // The character of the prefix
    char suffChar; // The character of the suffix
    int size;     // Total size of the segment
};

class SegmentTree {
private:
    vector<Node> tree;
    int n;

    // Helper function to merge two child nodes into a parent node
    Node merge(const Node& left, const Node& right) {
        Node res;
        res.size = left.size + right.size;
        res.prefChar = left.prefChar;
        res.suffChar = right.suffChar;

        // 1. Calculate Prefix Length
        res.prefLen = left.prefLen;
        // If the entire left segment is one character and it matches the right's prefix
        if (left.prefLen == left.size && left.prefChar == right.prefChar) {
            res.prefLen += right.prefLen;
        }

        // 2. Calculate Suffix Length
        res.suffLen = right.suffLen;
        // If the entire right segment is one character and it matches the left's suffix
        if (right.suffLen == right.size && right.suffChar == left.suffChar) {
            res.suffLen += left.suffLen;
        }

        // 3. Calculate Max Length
        // The max is at least the max of the strictly left or strictly right segments
        res.maxLen = max(left.maxLen, right.maxLen);
        // But it could also span across the middle boundary
        if (left.suffChar == right.prefChar) {
            res.maxLen = max(res.maxLen, left.suffLen + right.prefLen);
        }

        return res;
    }

    void build(const string& s, int node, int start, int end) {
        if (start == end) {
            // Base case: Leaf node represents a single character
            tree[node] = {1, 1, 1, s[start], s[start], 1};
            return;
        }
        int mid = start + (end - start) / 2;
        build(s, 2 * node, start, mid);
        build(s, 2 * node + 1, mid + 1, end);
        
        // Combine children to build the parent
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void updateNode(int node, int start, int end, int idx, char c) {
        if (start == end) {
            // Update the single character at the leaf
            tree[node] = {1, 1, 1, c, c, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            updateNode(2 * node, start, mid, idx, c);
        } else {
            updateNode(2 * node + 1, mid + 1, end, idx, c);
        }
        
        // After updating the child, re-evaluate the parent
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

public:
    SegmentTree(const string& s) {
        n = s.length();
        tree.resize(4 * n);
        if (n > 0) {
            build(s, 1, 0, n - 1);
        }
    }

    void update(int idx, char c) {
        updateNode(1, 0, n - 1, idx, c);
    }

    int getMax() {
        // The root node always contains the max length for the entire string
        return tree[1].maxLen;
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        SegmentTree st(s);
        vector<int> ans;
        
        int k = queryIndices.size();
        for (int i = 0; i < k; ++i) {
            // Update the character in the segment tree
            st.update(queryIndices[i], queryCharacters[i]);
            // The answer for this query is the overall max length stored at the root
            ans.push_back(st.getMax());
        }
        
        return ans;
    }
};