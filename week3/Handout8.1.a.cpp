
void Buffer::moveToWordBegin() {
    // if the character to the left of the cursor is a space
    // move back until it no longer is to skip over any
    // spaces that appear after the word
    while (cursor - 1 >= 0 && isspace(text[cursor - 1])) {
        moveCursorBackward();
    }
    // now move to the front of the word we are currently at -
    // meaning the letter to the left of the cursor is a space or
    // the cursor is at the beginning of the buffer
    while (cursor - 1 >= 0 && !isspace(text[cursor - 1])) {
        moveCursorBackward();
    }
}

