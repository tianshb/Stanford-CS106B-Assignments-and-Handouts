
void Buffer::moveToWordBegin() {
    // if the cursor is on a space,
    // move to the last character of the preceding word
    while (!before->IsEmpty() && isspace(before->peek())) {
        moveCursorBackward();
    }
    // move to the front of the word we're currently on
    while (!before->IsEmpty() && !isspace(before->peek())) {
        moveCursorBackward();
    }
}

