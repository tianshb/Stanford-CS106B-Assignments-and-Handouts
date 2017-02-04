
void Buffer::moveToWordBegin() {
    cellT *wordStart, curr, prev;
    space = head;
    if (cursor != head) {
        curr = head->link;
        prev = head;
        while (curr != cursor)
        {
            if (isspace(prev->ch) && !isspace(curr))
                wordStart = curr;
            prev = curr;
            curr = curr->link;
        }
        cursor = wordStart;
    }
}