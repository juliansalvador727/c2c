import pycountry as pc

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

with open("data/borders.csv", "r", encoding="utf-8") as f:
    lines = f.readlines()

with open("data/borders_iso3.csv", "w", encoding="utf-8") as f:
    for line in lines:
        countries = line.strip().split(",")
        codes = []
        for c in countries:
            if c in overrides:
                code = overrides[c]
            else:
                try:
                    code = pc.countries.lookup(c).alpha_3
                except LookupError:
                    print(f"Warning: Could not find ISO code for {c}")
                    code = c
            codes.append(code)
        # remove duplicates
        codes = list(dict.fromkeys(codes))
        f.write(",".join(codes) + "\n")
