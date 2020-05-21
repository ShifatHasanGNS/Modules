from math import log2, ceil

def char_to_binary(char, bit):
	n = ord(char)
	
	binary_txt = ""
	while n != 0:
		n, c = n//2, str(n%2)
		binary_txt += c
	binary_txt = ('0'*(bit - len(binary_txt))) + binary_txt
	
	return binary_txt[::-1]

def convert_text_to_binary(text):
	char_id_list = [ord(c) for c in text]
	char_id_list.sort()
	highest_bit = ceil(log2(char_id_list[-1]))
	
	binary_text = char_to_binary(text[0], highest_bit)
	for txt in text[1:]:
		binary_text += " " + char_to_binary(txt, highest_bit)
	
	return binary_text