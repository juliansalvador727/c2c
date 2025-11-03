<h3 align="center">c2c</h3>

  <p align="center">
    A C++ command line tool to find the shortest border-paths between two countries using ISO3 codes.
  </p>
</div>

---

## About

`c2c` is a command line tool that lets you find the shortest border-paths between countries using their ISO3 codes. You can either get a single shortest path or all shortest paths between two countries.

### Built With

- C++17
- Python (for CSVs)

---

## Getting Started

To get a local copy of this project running, follow these steps:

### Prerequisites

You need a C++ compiler and Python for data generation.

```sh
sudo apt install g++
python --version
```

### Installation

1. Clone the repository:

```sh
git clone https://github.com/juliansalvador727/c2c.git
cd c2c
```

2. Generate the CSV data used for borders:

```sh
python generate_data.py
```

3. Compile the C++ program:

```sh
g++ src/main.cpp src/graph.cpp src/pathfinder.cpp -Iinclude -o src/c2c
```

4. Run the executable:

```sh
cd src
./c2c path "CHN->USA"   # single shortest path
./c2c paths "CHN->USA"  # all shortest paths
```

---

## Usage

Examples:

```sh
# Single shortest path
./c2c path "FRA->AUT"
# Output:
# FRA ITA AUT

# All shortest paths
./c2c paths "FRA->AUT"
# Output:
# FRA DEU AUT
# FRA CHE AUT
# FRA ITA AUT
```

## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

## Acknowledgments

- [Best README Template](https://github.com/othneildrew/Best-README-Template)
- [GeoPandas](https://geopandas.org/)
- [ISO Country Codes Reference](https://www.iso.org/iso-3166-country-codes.html)
- [Natural Earth Country Data](https://www.naturalearthdata.com/downloads/110m-cultural-vectors/110m-admin-0-countries/)
