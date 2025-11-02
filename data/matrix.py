import geopandas as gpd
import pandas as pd

# Load shapefile
world = gpd.read_file("data/ne_110m_admin_0_countries.shp")

# Keep necessary columns
world = world[["ADMIN", "geometry"]]
world = world[world.geometry.notnull()]

# Build neighbors dictionary
neighbors = {}
for i, country in world.iterrows():
    borders = []
    for j, other in world.iterrows():
        if country.ADMIN != other.ADMIN and country.geometry.touches(other.geometry):
            borders.append(other.ADMIN)
    neighbors[country.ADMIN] = borders

# List of all countries sorted alphabetically
countries = sorted(neighbors.keys())

# Initialize adjacency matrix with 0s
matrix = pd.DataFrame(0, index=countries, columns=countries)

# Fill matrix
for country, border_list in neighbors.items():
    for neighbor in border_list:
        matrix.loc[country, neighbor] = 1

# Save to CSV
matrix.to_csv("data/matrix.csv")
