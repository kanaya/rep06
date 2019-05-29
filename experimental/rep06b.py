import argparse

parser = argparse.ArgumentParser(description='String splitter')
parser.add_argument('string', help='Target string')
parser.add_argument('--separator', default=':', help='String separator')

args = parser.parse_args()

t = args.string
s = args.separator

n = t.find(s)
sliced = t[n:]

print(sliced)
