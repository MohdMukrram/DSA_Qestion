ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        int n = 1;
        if (head == NULL || head->next == NULL || k == 0) return head;
        while(temp->next != NULL){
            n++;
            temp = temp->next;
        }

        k = k % n;
        if (k == 0) return head;
        int idx = n - k;
        int count = 0;
        ListNode* prev = NULL;
        ListNode* curr = head;

        for(int i=0;i<idx;i++){
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        temp ->next = head;
        head = curr;

        return head;
    }