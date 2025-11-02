import csv

filename = "data/borders.csv"
countries = set()
neighbors_dict = {}

with open(filename, newline='', encoding='utf-8') as f:
    reader = csv.reader(f)
    for row in reader:
        if len(row) != 2:
            print(f"Invalid row (wrong number of columns): {row}")
            continue
        country, neighbor = row
        countries.add(country)
        if country not in neighbors_dict:
            neighbors_dict[country] = []
        neighbors_dict[country].append(neighbor)

# 1. Check every country has at least one neighbor or NONE
for country, neighbors in neighbors_dict.items():
    if all(n.upper() in ("NONE", "NULL") for n in neighbors):
        continue  # valid island country
    if len(neighbors) == 0:
        print(f"Country with no neighbors listed: {country}")

# 2. Check for duplicate neighbor entries
for country, neighbors in neighbors_dict.items():
    if len(neighbors) != len(set(neighbors)):
        print(f"Country with duplicate neighbors: {country} -> {neighbors}")

# 3. Check all neighbor entries exist as countries (unless NONE/NULL)
for country, neighbors in neighbors_dict.items():
    for n in neighbors:
        if n.upper() in ("NONE", "NULL"):
            continue
        if n not in neighbors_dict:
            print(f"Neighbor {n} of {country} is not listed as a country itself.")

# 4. Optional: Check for symmetric borders (A->B implies B->A)
for country, neighbors in neighbors_dict.items():
    for n in neighbors:
        if n.upper() in ("NONE", "NULL"):
            continue
        if country not in neighbors_dict.get(n, []):
            print(f"Non-symmetric border: {country} -> {n}, but {n} -> {country} missing")
