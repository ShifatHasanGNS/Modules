def matrix_input(matrix_type, row, column):
	
	temp = []
	matrix = []
	matrix_row = []
	
	for r in range(row):
		
		if matrix_type is int:
			temp = [int(item) for item in input().split()]
		
		elif matrix_type is float:
			temp = [float(item) for item in input().split()]
		
		elif matrix_type is str:
			temp = [item for item in input().split()]
		
		else:
			return matrix

		for c in range(column):
			try:
				matrix_row.append(temp[c])
			except: continue
		matrix.append(matrix_row)
		matrix_row = []
	return matrix


def show_matrix(matrix):
	row = len(matrix)
	
	if row == 0:
		return
		
	elif row == 1:
		print(matrix)
		
	elif row == 2:
		temp = '[' + str(matrix[0])[0:-1]+ '],'
		print(temp)
		
		temp = ' ' + str(matrix[1])[0:-1] + ']]'
		print(temp)
		
	elif row > 2:
		temp = '[' + str(matrix[0])[0:-1] + '],'
		print(temp)
		
		for r in range(1, row-1):
			temp = ' ' + str(matrix[r])[0:-1] + '],'
			print(temp)
			
		temp = ' ' + str(matrix[-1])[0:-1] + ']]'
		print(temp)
