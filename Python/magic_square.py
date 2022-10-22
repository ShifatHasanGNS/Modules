def generate_magic_square(n):
	magic_square = [[0 for i in range(n)] for i in range(n)]
	
	r = 0
	c = int((n-1)/2)
	magic_square[r][c] = 1
	
	count = 1
	
	for _ in range(n*n-1):
		count += 1
		
		if r==0 and c>=0 and c<(n-1):
			r = n-1
			c = c+1
		elif r>0 and r<=(n-1) and c==(n-1):
			r = r-1
			c = 0
		elif r==n-2*(c+1) or r==2*(n-c-1):
			r = r+1
		else:
			r = r-1
			c = c+1
			
		magic_square[r][c] = count
		
	return magic_square

def show_matrix(matrix):
	print('\n'.join(['\t'.join([str(c) for c in r]) for r in matrix]))


if __name__ == '__main__':
	s = generate_magic_square(4)
	show_matrix(s)