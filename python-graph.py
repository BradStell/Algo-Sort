import re 	# regular expressions
from matplotlib import pyplot as plt

filePath = 'Time-Outputs.txt'

with open(filePath, 'r') as f:
	
	file_content = f.read()
	
	ins_sort_size_list = re.findall(r'### Insertion Sort ###\nArray Size: ([0-9]+)', file_content)
	ins_sort_time_list = re.findall(r'### Insertion Sort ###\n.+\nAverage Time: ([0-9\.]+)', file_content)
	
	sel_sort_size_list = re.findall(r'### Selection Sort ###\nArray Size: ([0-9]+)', file_content)
	sel_sort_time_list = re.findall(r'### Selection Sort ###\n.+\nAverage Time: ([0-9\.]+)', file_content)
	
	bub_sort_size_list = re.findall(r'### Bubble Sort ###\nArray Size: ([0-9]+)', file_content)
	bub_sort_time_list = re.findall(r'### Bubble Sort ###\n.+\nAverage Time: ([0-9\.]+)', file_content)
	
	bf_sort_size_list = re.findall(r'### Brute Force ###\nArray Size: ([0-9]+)', file_content)
	bf_sort_time_list = re.findall(r'### Brute Force ###\n.+\nAverage Time: ([0-9\.]+)', file_content)
	
	plt.style.use('ggplot')
	
	# Plot the different sorting algos
	plt.plot(ins_sort_size_list, ins_sort_time_list, 'g', label='insertion sort', linewidth=5)
	plt.plot(sel_sort_size_list, sel_sort_time_list, 'c', label='selection sort', linewidth=5)
	plt.plot(bub_sort_size_list, bub_sort_time_list, 'r', label='bubble sort', linewidth=5)
	plt.plot(bf_sort_size_list, bf_sort_time_list, color='purple', label='brute force', linewidth=5)
	
	plt.legend()
	
	#plt.xscale('log', basex=2)
	#plt.yscale('log', basey=10)
	
	
	plt.title('Sorting Algo Times')
	plt.ylabel('Milliseconds')
	plt.xlabel('Size')	
	
	plt.show()