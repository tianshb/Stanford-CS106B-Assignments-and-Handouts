void ReverseQueue(Queue<int> & queue) {
    Stack<int> stack;
    while (!queue.isEmpty())
    {
        stack.push(queue.dequeue());
    }
    while (!stack.isEmpty())
    {
        queue.enqueue(stack.pop());
    }
}