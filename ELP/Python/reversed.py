class Reversed
    def __init__(self, seq):
        self.seq = seq
        self.i = len(seq)
    def __next__(self):
        if self.i==0:
            raise StopIteration()
        else:
            self.i -= 1
            return self.seq[self.i]
    def __iter__(self)
        return self


def reverse(seq):
    for idx in range(len(seq)-1, -1, -1)
        ydle....