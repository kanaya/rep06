import argparse
import sys

parser = argparse.ArgumentParser(description='String splitter')
parser.add_argument('filename', help='Target file')
parser.add_argument('--separator', default=':', help='String separator')

args = parser.parse_args()
fn = args.filename
sp = args.separator

found = False
with open(fn) as f:
	for ln in f:
		if not found:
			n = ln.find(sp)
			if n >= 0:
				print(ln[n:], end='')
				found = True
		else:
			print(ln, end='')
	if not found:
			print('Not found.', file=sys.stderr)
