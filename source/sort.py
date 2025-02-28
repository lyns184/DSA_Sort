import numpy as np
import time

def process(data, outfile, test_index):
    start = time.time()
    sorted_data = np.sort(data)
    end = time.time()
    duration = (end - start) * 1000 
    outfile.write(f"Sorting time {test_index}: {duration:.3f} ms\n")

def main():
    with open("test.txt", "r") as infile, open("time.txt", "w") as outfile:
        test_index = 1
        for line in infile:
            data = np.array(list(map(float, line.split())))
            process(data, outfile, test_index)
            test_index += 1

if __name__ == "__main__":
    main()
