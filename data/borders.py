import geopandas as gpd

# Load shapefile
world = gpd.read_file("ne_110m_admin_0_countries.shp")

# Keep only necessary columns
world = world[["ADMIN", "geometry"]]

# Ensure geometries are valid
world = world[world.geometry.notnull()]

neighbors = {}

for i, country in world.iterrows():
    borders = []
    for j, other in world.iterrows():
        if country.ADMIN != other.ADMIN and country.geometry.touches(other.geometry):
            borders.append(other.ADMIN)
    neighbors[country.ADMIN] = borders
    
with open("borders.csv", "w", encoding="utf-8") as f:
    for country, border_list in neighbors.items():
        line = ",".join([country] + border_list)
        f.write(line + "\n")
