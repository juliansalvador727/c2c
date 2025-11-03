<a id="readme-top"></a>

[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![project_license][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]

<br />
<div align="center">
  <a href="https://github.com/julian/c2c">
    <img src="images/logo.png" alt="Logo" width="80" height="80">
  </a>

<h3 align="center">c2c</h3>

  <p align="center">
    A C++ CLI tool to find the shortest land paths between countries using ISO3 codes.
    <br />
    <a href="https://github.com/julian/c2c"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/julian/c2c">View Demo</a>
    &middot;
    <a href="https://github.com/julian/c2c/issues/new?labels=bug&template=bug-report---.md">Report Bug</a>
    &middot;
    <a href="https://github.com/julian/c2c/issues/new?labels=enhancement&template=feature-request---.md">Request Feature</a>
  </p>
</div>

---

## About The Project

[![Product Name Screen Shot][product-screenshot]](https://example.com)

`c2c` is a command-line program that lets you find the shortest land paths between countries using their ISO3 codes. You can either get a **single shortest path** or **all shortest paths** between two countries.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

### Built With

- C++17
- Python 3 (for generating CSV data)
- Linux/Windows command line compatible

<p align="right">(<a href="#readme-top">back to top</a>)</p>

---

## Getting Started

To get a local copy of this project running, follow these steps:

### Prerequisites

You need a C++ compiler (g++ recommended) and Python 3 for data generation.

```sh
sudo apt install g++   # on Ubuntu / WSL
python3 --version      # confirm Python is installed
```

### Installation

1. Clone the repository:

```sh
git clone https://github.com/julian/c2c.git
cd c2c
```

2. Generate the CSV data used for borders:

```sh
python3 generate_data.py
```

3. Compile the C++ program:

```sh
g++ src/main.cpp src/graph.cpp src/pathfinder.cpp -Iinclude -o src/c2c
```

4. Run the executable:

```sh
./src/c2c path CHN->USA   # single shortest path
./src/c2c paths CHN->USA  # all shortest paths
```

<p align="right">(<a href="#readme-top">back to top</a>)</p>

---

## Usage

Examples:

```sh
# Single shortest path
./src/c2c path FRA->AUT
# Output:
# FRA ITA AUT

# All shortest paths
./src/c2c paths FRA->AUT
# Output:
# FRA DEU AUT
# FRA CHE AUT
# FRA ITA AUT
```

<p align="right">(<a href="#readme-top">back to top</a>)</p>

---

## Roadmap

- [x] Generate country borders CSV from shapefile
- [x] Convert country names to ISO3 codes
- [x] Implement Graph class to read CSV
- [x] Implement shortest path and all shortest paths algorithms
- [ ] Add WSL / Linux argument handling fixes
- [ ] Optional GUI visualization

<p align="right">(<a href="#readme-top">back to top</a>)</p>

---

## Contributing

Contributions are welcome! Fork the repo, create a feature branch, commit, push, and open a pull request.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<p align="right">(<a href="#readme-top">back to top</a>)</p>

---

## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

---

## Contact

Julian Salvador - [@julian](https://twitter.com/julian) - [julian@example.com](mailto:julian@example.com)

Project Link: [https://github.com/julian/c2c](https://github.com/julian/c2c)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

---

## Acknowledgments

- [Best README Template](https://github.com/othneildrew/Best-README-Template)
- [GeoPandas](https://geopandas.org/)
- [ISO Country Codes Reference](https://www.iso.org/iso-3166-country-codes.html)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- MARKDOWN LINKS & IMAGES -->

[contributors-shield]: https://img.shields.io/github/contributors/github_username/repo_name.svg?style=for-the-badge
[contributors-url]: https://github.com/github_username/repo_name/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/github_username/repo_name.svg?style=for-the-badge
[forks-url]: https://github.com/github_username/repo_name/network/members
[stars-shield]: https://img.shields.io/github/stars/github_username/repo_name.svg?style=for-the-badge
[stars-url]: https://github.com/github_username/repo_name/stargazers
[issues-shield]: https://img.shields.io/github/issues/github_username/repo_name.svg?style=for-the-badge
[issues-url]: https://github.com/github_username/repo_name/issues
[license-shield]: https://img.shields.io/github/license/github_username/repo_name.svg?style=for-the-badge
[license-url]: https://github.com/github_username/repo_name/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/linkedin_username
[product-screenshot]: images/screenshot.png
