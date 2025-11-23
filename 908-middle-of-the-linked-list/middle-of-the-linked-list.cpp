// Time Complexity = O(n); as we are traversing each node in the LL
// Space Complexity = O(n); as we are storing each node in a vector

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *temp = head;
        vector<ListNode*> nodes;

        while(temp != NULL){
            nodes.push_back(temp);
            temp = temp->next;
        }

        int mid = floor(nodes.size() / 2);

        return nodes[mid];
    }
};