with open("/home/pbernarbe/Python/species-intro.txt") as f:
	for line in f:
		words = [w.lower() for w in line.split()]
		for word in words:
			for  c in "{}[]-_,.;:!?§\",":
				if c in word:
					word = word.replace(c,"")
			if word not in histogram:
				histogram[word] = 1
			else:
				histogram[word] += 1

for k in sorted(list(histogram.keys())):
	print("{0:18} | {1}".format(k,histogram[k] * "*"))
