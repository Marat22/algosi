import sys

class ListView:
    def __init__(self, storage, start=0, length=None, is_root=False):
        self.storage = storage
        self.start = start
        self.length = length
        self.is_root = is_root

    def get(self, i):
        if self.is_root:
            return self.storage[i - 1]
        else:
            return self.storage[self.start + i - 1]

    def set(self, i, x):
        if self.is_root:
            self.storage[i - 1] = x
        else:
            self.storage[self.start + i - 1] = x

    def add(self, x):
        if not self.is_root:
            raise RuntimeError(f"why {self.storage=}, {self.start=}, {self.length=}, {self.is_root=}")
        self.storage.append(x)

def main():
    data = sys.stdin.read().splitlines()
    if not data:
        return
    n = int(data[0])
    lists = {}
    output_lines = []

    for line in data[1:n+1]:
        line = line.strip()
        if line.startswith('List'):
            parts = line.split('=', 1)
            left = parts[0].strip()
            right = parts[1].strip()
            name = left.split()[1]

            if right.startswith('new List'):
                inner = right.split('(', 1)[1].rsplit(')', 1)[0]
                if inner == '':
                    nums = []
                else:
                    nums = list(map(int, inner.split(',')))
                storage = nums
                lst_obj = ListView(storage, is_root=True)
                lists[name] = lst_obj
            else:
                if '.subList(' not in right:
                    raise ValueError(f"whaaat {right=}")
                obj_part, args_part = right.split(".subList(", 1)
                obj_name = obj_part.strip()
                args = args_part.rstrip(')').strip()
                from_idx, to_idx = map(int, args.split(','))
                a = lists[obj_name]
                new_start = a.start + (from_idx - 1)
                new_length = to_idx - from_idx + 1
                lst_obj = ListView(a.storage, start=new_start, length=new_length, is_root=False)
                lists[name] = lst_obj
        else:
            if '.get(' in line:
                obj_name, rest = line.split('.get(', 1)
                i = int(rest.rstrip(')'))
                val = lists[obj_name].get(i)
                output_lines.append(str(val))
            elif '.set(' in line:
                obj_name, rest = line.split(".set(", 1)
                args = rest.rstrip(')')
                i, x = map(int, args.split(','))
                lists[obj_name].set(i, x)
            elif '.add(' in line:
                obj_name, rest = line.split('.add(', 1)
                x = int(rest.rstrip(')'))
                lists[obj_name].add(x)
            else:
                raise ValueError(f"unkown command {line=}")

    print("\n".join(output_lines))

if __name__ == "__main__":
    main()
