f_input = open('input.in', 'r')
f_output = open('output.out', 'w')


class Stack:
    def __init__(self):
        self.items = []

    def is_empty(self):
        return self.items == []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def peek(self):
        return self.items[len(self.items) - 1]

    def size(self):
        return len(self.items)


def error_message():
    print("NO")
    exit(0)

s = Stack()
for line in f_input:
    a = line.split()
    for item in a:
        if item == '[' or item == '{' or item == '(':
            s.push(item)
        if item == ')':
            if s.is_empty:
                error_message()
            elif s.peek == '(':
                s.pop()
            else:
                error_message()
        if item == '}':
            if s.is_empty:
                error_message()
            elif s.peek == '{':
                s.pop()
            else:
                error_message()
        if item == ')':
            if s.is_empty:
                error_message()
            elif Stack.peek == '[':
                s.pop()
            else:
                error_message()
    if s.is_empty():
        f_output.write("YES")
    else:
        error_message()

f_input.close()
f_output.close()
