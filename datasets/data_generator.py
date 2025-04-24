from faker import Faker
import random
import argparse

fake = Faker()

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--count", type=int, default=1000)
    parser.add_argument("--output", type=str, default="datasets/csv/data.csv")
    args = parser.parse_args()

    with open(args.output, "w") as f:
        for i in range(args.count):
            f.write(f"{fake.name()};{fake.company()};{random.randint(2000, 2025)};{fake.license_plate()};{fake.color()}\n")

if __name__ == "__main__":
    main()
