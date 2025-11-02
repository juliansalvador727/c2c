import pycountry as pc
import csv

# Overrides for special cases
overrides = {
    "NONE": "NONE",
    "Russia": "RUS",
    "East Timor": "TLS",
    "The Bahamas": "BHS",
    "Falkland Islands": "FLK",
    "French Southern and Antarctic Lands": "ATF",
    "Brunei": "BRN",
    "Kosovo": "XKX",
    "Cyprus": "CYP",
    "Democratic Republic of the Congo": "COD",
    "Ivory Coast": "IVC",
    "Palestine": "PSE",
    "Somaliland": "SML",
    "Turkey": "TUR",
    "Northern Cyprus": "NCP"
}

def to_iso3(name):
    if name in overrides:
        return overrides[name]
    try:
        return pc.countries.lookup(name).alpha_3
    except LookupError:
        print(f"Warning: Could not find ISO code for {name}")
        return name

# Read border data
borders = {}
all_countries = set()

with open("data/borders.csv", "r", encoding="utf-8") as f:
    reader = csv.reader(f)
    for country, neighbor in reader:
        c_iso = to_iso3(country)
        n_iso = to_iso3(neighbor)
        all_countries.update([c_iso, n_iso])
        borders.setdefault(c_iso, set()).add(n_iso)

# Sort countries alphabetically by ISO3
all_countries = sorted(all_countries)

# Build adjacency matrix
matrix = []
for c in all_countries:
    row = []
    for n in all_countries:
        if c == n:
            row.append(0)  # No self-border
        elif c in borders and n in borders[c]:
            row.append(1)
        else:
            row.append(0)
    matrix.append(row)

# Write CSV with headers
with open("data/borders_matrix_iso3.csv", "w", newline="", encoding="utf-8") as f:
    writer = csv.writer(f)
    writer.writerow([""] + all_countries)  # top header row
    for c, row in zip(all_countries, matrix):
        writer.writerow([c] + row)
