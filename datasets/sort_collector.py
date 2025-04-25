import subprocess
import json
import os
import random
import time
from pathlib import Path

AMOUNT_OF_RUNS = 20
DATASET_SIZES = [int(100 + i * ((100000 - 100) / AMOUNT_OF_RUNS)) for i in range(AMOUNT_OF_RUNS)] # [100, 1000, 10000, 100000]
DATASETS_PER_SIZE = 1
CSV_DIR = "datasets/csv"
BINARY_PATH = "bin/lab-01.elf"
RESULTS_FILE = "datasets/sort_results.json"

def ensure_directory_exists(directory):
    Path(directory).mkdir(parents=True, exist_ok=True)

def generate_dataset(size, filename):
    print(f"[DEBUG] Generating dataset of size {size} in file {filename}")
    cmd = ["python3", "datasets/data_generator.py", f"--count={size}", f"--output={filename}"]
    subprocess.run(cmd, check=True)

def run_sorting_and_collect_results(filename):
    print(f"[Debug] Running sorting for file {filename}")
    result = subprocess.run([BINARY_PATH, filename], capture_output=True, text=True)
    print(f"        Ended successfully")
    output = result.stdout
    times = {}
    
    algorithms = ["std::sort", "SelectionSort", "MergeSort", "QuickSort"]
    for algorithm in algorithms:
        for line in output.split('\n'):
            if f"{algorithm} completed in" in line:
                time_str = line.split("in")[1].strip().split()[0]
                times[algorithm] = float(time_str)
                break
    
    return times

def main():
    ensure_directory_exists(CSV_DIR)
    
    all_results = {}
    
    for size in DATASET_SIZES:
        all_results[size] = []
        
        for i in range(DATASETS_PER_SIZE):
            dataset_filename = f"{CSV_DIR}/data_{size}_{i+1}.csv"
            
            generate_dataset(size, dataset_filename)
            
            sort_times = run_sorting_and_collect_results(dataset_filename)
            
            result_entry = {
                "dataset": dataset_filename,
                "times": sort_times
            }
            all_results[size].append(result_entry)
            
            time.sleep(1)
    
    with open(RESULTS_FILE, 'w') as f:
        json.dump(all_results, f, indent=4)
    
    print(f"Все результаты сохранены в {RESULTS_FILE}")

if __name__ == "__main__":
    main()
