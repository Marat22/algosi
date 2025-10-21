# https://contest.yandex.ru/contest/80941/problems/I/

class Node:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right


class Parser:
    def __init__(self, expr):
        self.expr = expr.replace(' ', '')
        self.pos = 0

    def parse(self):
        return self.expression()
    
    def expression(self):
        left = self.term()
        while self.pos < len(self.expr) and self.expr[self.pos] in '+-':
            op = self.expr[self.pos]
            self.pos += 1
            right = self.term()
            left = Node(op, left, right)
        return left
    
    def term(self):
        left = self.factor()
        while self.pos < len(self.expr) and self.expr[self.pos] in '*/':
            op = self.expr[self.pos]
            self.pos += 1
            right = self.factor()
            left = Node(op, left, right)
        return left
    
    def factor(self):
        left = self.element()
        if self.pos < len(self.expr) and self.expr[self.pos] == '^':
            op = self.expr[self.pos]
            self.pos += 1
            right = self.factor()
            return Node(op, left, right)
        return left
    
    def element(self):
        if self.expr[self.pos] == '(':
            self.pos += 1
            node = self.expression()
            self.pos += 1
            return node
        else:
            var = self.expr[self.pos]
            self.pos += 1
            return Node(var)

def render(node):
    if node.left is None:
        return {
            'lines': [node.value],
            'width': 1,
            'height': 1,
            'root': 0,
        }
    
    left = render(node.left)
    right = render(node.right)

    max_height = max(left['height'], right['height'])
    while left['height'] < max_height:
        left['lines'].append(' ' * left['width'])
        left['height'] += 1
    while right['height'] < max_height:
        right['lines'].append(' ' * right['width'])
        right['height'] += 1

    new_width = left['width'] + 5 + right['width']
    right_root_abs = left['width'] + 5 + right['root']

    total_space = right_root_abs - left['root'] - 1
    op_str = f"[{node.value}]"
    total_dashes = total_space - 3

    left_dist = left['width'] - 1 - left['root']
    right_dist = right['root']

    num_left_dashes = (total_dashes * (left_dist + 1)) // (left_dist + right_dist +2)
    # num_right
    op_start = left['root'] + 1 + num_left_dashes

    top_line = [' '] *new_width
    top_line[left['root']] = '.'
    for i in range(left['root'] + 1, op_start):
        top_line[i] = '-'
    for i, c in enumerate(op_str):
        top_line[op_start + i] = c
    for i in range(op_start + 3, right_root_abs):
        top_line[i] = '-'
    top_line[right_root_abs] = '.'

    second_line = [' '] * new_width
    second_line[left['root']] = '|'
    second_line[right_root_abs] = '|'

    result_lines = [''.join(top_line), ''.join(second_line)]
    for i in range(max_height):
        line = left['lines'][i] + ' ' * 5 + right['lines'][i]
        result_lines.append(line)
    new_root = op_start + 1

    return {'lines': result_lines, 'width':new_width, 'height':len(result_lines),'root':new_root}

expr = input().strip()
parser = Parser(expr)
tree = parser.parse()
result = render(tree)


for line in result['lines']:
    print(line)
